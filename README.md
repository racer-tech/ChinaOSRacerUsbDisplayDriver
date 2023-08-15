# RacerTech UsbDisplay Driver
支持系统（统信，麒麟，Ubuntu）
## 所需内核模块介绍
### EVDI
EVDI(Embedded Virtual Display Interface)是一个开源的Linux内核模块，用于来显示连接的虚拟化和多显示器的扩展。允许讲USB连接将外部显示器连接到计算机上。

EVDI允许通过USB连接将额外的显示器或者显示设备连接到计算器，从而实现多荧幕显示，EVDI提供了与显示设备通信的接口，使得操作系统和应用程序可以操作USB设备进行显示，在一些需要便捷显示器来显示的时候，可以直接使用USB接口直接进行使用

EVDI在Racertech的驱动中主要提供在linux上实现多屏幕扩展和虚拟现实功能，用户可以用EVDI模块在Linux系统上通过USB连接并使用外部设备。

## 驱动介绍
### 功能介绍
Racertech于2022年开发了专门基于Linux国产系统（UOS，Kylin）两大国产驱动厂商去开发usbdisp_linux驱动，目前使用RacerTech芯片的外接USB显示器例如签批屏，扩展屏等在x86_64和arm64两个比较常见的架构上流畅使用。
* USB热插拔
* 支持多分辨率
* 可更改分辨率
* 可旋转
* 睡眠/唤醒
* 保持显示设置
* 屏幕可随系统开关而开关
* 在退出线程后可关闭显示器
### 待开发功能
* 多扩展显示器支持（目前linux只支持单扩展）
* 亮度调节
* 根据重力感应事件旋转

### 代码架构
* RacerDisplay (使用Cmake进行Bin档构建)

* conf (驱动配置补丁)

* libevdipp(evdi接口部分)

* libusbdisp(library以及xrandr和usbdisp类的声明，会提供一些于USB相关的显示的功能和方法)

* CMakelists.txt(用于构建bin档的文件夹)


## 编译步骤
### 如何构建bin档
首先，构建可执行的bin档，一定是要先进行环境的编译的，当环境编译完成以后，才能进行bin档的构建，此driver编译的形式还是使用Cmake以及makefile的方式

在CHinaOSRacerUsbDisplayDriver目录下，创建一个Build文件夹,进入这个文件夹进行环境编译。
```
mkdir build
cd build
```
先试用cmake编译
```
cmake ..
```
这里可以去检查build下是否存在可编译的makefile文件

使用Make指令编译生成bin档
```
make install
```
编译完成后,进入stage文件夹下的bin文件夹下，启动驱动文件RacerDisplay
```
cd stage/bin
sudo ./RacerDisplay
```
