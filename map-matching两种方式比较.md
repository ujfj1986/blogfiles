两种实现方式比较

1. 两种方式
    a. 提供FFLocationManager API
    b. 直接使用socket进行连接

2. 优点
    2.1. FFLocationManager方式
        2.1.1 平台接口统一
        2.1.2 符合Android 架构
        2.1.3 安全网络
    2.2. 直接socket方式
        2.2.1 时延低
        2.2.2 实现简单
        2.2.3 不依赖Android API
3. 缺点
    3.1. FFLocationManager方式
        3.1.1 实现复杂
        3.1.2 时延长
    3.2. 直接socket方式
        3.2.1 加密传输方式实现复杂
        3.2.2 
