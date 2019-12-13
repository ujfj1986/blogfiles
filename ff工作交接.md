# FF 工作总结

我在FF的工作主要涉及IOV系统中的WiFi, Ethernet, GNSS及整个网络架构。

WiFi方面的工作主要是WiFi芯片STA和Hotspot基本功能的bring up和MPC控制HPC上的WiFi Hotspot功能。

Ethernet方面的工作主要是维护Ethernet Framework、保持Ethernet接口始终是up状态和MPC&HPC相互发现功能的开发。

GNSS方面的工作主要是GNSS协议栈的开发，位置信息的网络分发功能开发和MPC上通过gnss@1.0-service给native程序进行位置分发功能的开发。

网络架构方面的工作主要是在MPC&HPC上网络报文的转发配置工作。

所有的这些工作都离不开IOV系统的硬件架构。

### 1. 硬件架构

请查看文档[Network_Management_Architecture][1]

### 2. 网络架构

[同上][1]

[Confluence](https://confluence.faradayfuture.com/display/BISP/IP+ADDRESS+ASSIGNMENT)

### 3. WiFi 开发功能

WiFi相关开发功能主要是在MPC上控制HPC上的热点功能，主要的修改是在目录frameworks/opt/net/wifi/service/java/com/android/server/wifi/目录下。

主要修改文件是WifiApController.java和ParcelableUtil.java。

ParcelableUtil主要定义和实现了Parcelable子类的串行化和反串行化，是一个工具类。

WifiApController根据当前运行的设备的不同，有不同的功能，详细介绍如下：

    MPC：
    * 打开、关闭HPC热点
    * 获取当前HPC热点状态
    * 获取当前HPC热点配置
    * 设置当前HPC热点配置
    * 监听Ethernet发现HPC设备广播，如果收到广播，建立到HPC的连接，
    创建接收热点状态变化的线程
    * 监听Ethernet失去HPC设备广播，如果收到广播，断开到HPC的连接，
    关闭接收热点状态变化的线程
    * 接收WiFi service注册热点状态及连接个数变化的回调
    * 接收到热点状态变化命令时，广播热点状态变化Intent
    * 接收到热点连接个数变化命令时，调用回调接口

    HPC：
    * 接收到打开、关闭热点命令时，打开、关闭本地热点
    * 接收获取热点状态命令时，返回当前热点状态
    * 接收获取热点配置命令时，返回当前热点配置
    * 接收设置热点配置命令时，设置当前热点配置
    * 监听Ethernet发现MPC设备广播，如果收到广播，建立到MPC的连接，
    创建接收热点控制命令的线程
    * 监听Ethernet失去MPC设备广播，如果收到广播，断开到MPC的连接，
    关闭接收热点控制命令的线程
    * 向WiFi Service注册热点状态及连接个数变化的回调，在连接个数变化时，发送连接个数变化命令给MPC
    * 监听热点状态变化广播，如果接收到广播，发送热点状态变化命令给MPC

另外，由于Android打开、关闭热点接口的变动（从WifiManager改为ConnectivityManager），我们还在ConnectivityService中增加了FFExtTethering类， 这个类的主要功能如下：

    MPC：
    * 打开关闭HPC热点
    HPC：
    * 当设备启动时，检查上次热点状态，如果热点上次是使能状态，打开热点功能
    * 监听屏幕的SCREEN_ON/SCREEN_OFF广播，当接收到SCREEN_ON时，检查热点保存的状态，如果热点保存状态为使能状态，打开热点功能；当接收到SCREEN_OFF时，关闭热点功能，不保存热点的状态。

这个类在framework/base/services/core/java/com/android/server/connectivity/目录下。

### 4. Ethernet开发功能

Framework Ethernet Service主要开发功能如下：

    * 每隔1s，组播当前设备信息的报文
    * 接收到组播报文后，如果设备为在发现设备列表中，发送发现新设备Intent，如果设备已经在发现设备列表中，重置其定时器。
    * 如果定时器超时，将设备移出发现设备列表，发送丢失设备Intent。

主要涉及目录framwork/opt/net/ethernet/。

[Ethernet Confluence][2]

### 5. GNSS功能

由于GNSS芯片位于MMU上，所以MPC、HPC上的应用如果需要获取位置信息，需要通过网络从MMU上的GPS Service上获取。

GNSS详细功能如下：

    MPC、HPC：
    * 实现GNSS HAL层接口
    * 等待MMU更新位置信息
    * 通过gnss@1.0-service给native层应用更新位置信息

    MMU：
    * 实现通过串口、I2C接口读取位置信息
    * 实现GNSS协议栈
    * 实现GNSS芯片配置
    * 发送位置信息给客户端

主要代码目录如下：

    MPC、HPC：
    * hardware library代码：hardware/gps/
    * MMU gps client端代码： vendor/ff/properties/gps

    MMU:
    * MMU gps service端代码：vendor/ff/properties/gps/

### 6. 整体网络架构改动

为了实现上文的网络架构，我们在MPC、HPC上做了如下改动：

    MPC：
    * 当WiFi Station模式打开并连接到网络时，我们会打开tethering功能，并将upstream配置成wifi，downstream配置成ethernet。

    HPC：
    * 当WiFi Hotspot模式打开是，我们需要将upstream配置成ethernet



[1]:(./Network_Management_Architecture.pptx)
[2]:(https://confluence.faradayfuture.com/display/BISP/IoV_Ethernet/)
