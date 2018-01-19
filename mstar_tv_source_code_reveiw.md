# mstar tv source code reveiw
----

### 1. 全编译命令
    
    . build/envsetup.sh
    lunch aosp_mangosteen-userdebug
    make -j8
    
### 2. supernova
supernova是mstar的native平台，它在目录$(ROOT_DIR)/vendor/mstar/supernova目录下。
其中在目录project/tvos/下是mstar的一个native framework。

在device/mstar/common/libraries/tvapi目录下，是mstar的Android framework tvapi的实现。

### 3. usb driver
在板子的/system/lib/modules目录下，有一个名叫usbcimoduledrv.ko的文件，怀疑是板子的usb驱动程序，但是板子的驱动程序不应该是build-in的吗？

### 4. 板子adb连接方法
板子通过有线与路由器相连，在启动后，获得ip地址192.168.1.100，在PC上使用命令adb connect 192.168.1.100可以通过网络连接板子adb进程，但是在执行adb shell的时候，会提示“设备未鉴权”，需要在板子上点击确定按键。可以通过如下命令点击：

    input keyevent 61
    input keyevent 61
    input keyevent 66

命令为输入两个tab键和一个确定键。

