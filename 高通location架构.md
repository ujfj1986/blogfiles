# 高通 Android O location 架构

## 1. 新特性 
高通在这次的android O升级后，引入了很多location的变动，包括如下特性：
    LBS
    Network Location
    Location Launcher
    。。。

## 2. GPS相关宏定义
在文件 vendor/qcom/proprietary/common/msm8996/BoardConfigVendor.mk 中定义 BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE

    device/qcom/msm8996/
    device/qcom/common/

## 3. 代码目录
    vendor/qcom/propietary/gps
    vendor/qcom/proprietary/interfaces/gnss/1.0
    

    