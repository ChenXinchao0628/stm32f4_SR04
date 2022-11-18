# STM32-HAL库SR04超声波测距


本仓库包含以下内容：

1. HAL工程
2. keil5工程

两种实现方式：

1. stm32f4_SR04_input capture 输入捕获方式
2. stm32f4_SR04_timer_to_time 定时器计时方式


## 使用说明

1. 该例程可直接烧录至STM32F4芯片运行，输入捕获方式使用了一个定时器，一个GPIO；定时器计时方式使用了一个定时器，两个GPIO
2. 定时器相关的define设置在SR04.h文件，移植注意修改
3. 详细配置请查阅HAL配置及程序注释
