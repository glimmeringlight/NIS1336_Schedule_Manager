<p align="center">
    <h1 align="center">NIS1336_Schedule_Manager</h1>
</p>
<p align="center">
    日程管理软件
</p>

## 项目功能

- [x] 支持多用户注册、登录以及密码修改
- [x] 支持用户增加、删除任务
- [x] 支持用户设置任务提醒时间，并且按时提醒
- [x] 支持命令行、shell循环、图形界面三种交互方式



## 源代码结构说明

`QT_src`下包含图形界面（QT）的源代码，需要使用`qmake`编译。

`src`下包含项目的核心功能代码，包括文件接口函数、命令行交互、周期性检查。

`scripts`下包含供测试用的shell脚本。

`bin`目录中包含编译后的可执行的二进制文件。

## 项目编译

在项目根目录下执行：`make main`用户编译命令行交互界面，`make cli`用户编译命令行接口供用户或图形界面调用，`make all`同时编译上述两者。编译得到的二进制文件存放在`bin`目录下。

## 使用该项目

首先切换到`bin`目录：

```bash
cd ./bin/
```

而后，运行命令行交互界面：

```bash
./main
```

图形界面：

```bash
./Schedule
```

命令行接口：

```bash
./cli help
```



