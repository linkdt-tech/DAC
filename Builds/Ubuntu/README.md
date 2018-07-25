# Ubuntu 编译
## 系统需求
- 建议 Ubutun 16.04 及以上版本

## 安装工具
- sudo apt-get install git

## 下载源码
- git clone https://github.com/linkdt-tech/DAC.git dacd

## 安装开发环境依赖
- 进入编译目录
```
> cd Builds/Ubuntu
```
- 分别执行下面指令
```
> sudo chmod a+x *.sh
> sudo ./install_rippled_depends_ubuntu.sh
> ./install_boost.sh
```
- 在 ~/.bashrc 文件中保存 BOOST_ROOT 环境变量

```
export BOOST_ROOT=~/dacd/Builds/Ubuntu/boost_1_63_0
```
- 让 BOOST_ROOT 环境变量生效
```
> source ~/.bashrc
```

## 编译 dacd
- 重新进入源码根目录
```
> cd ~/dacd
```
- 执行编译指令
```
> scons --static --enable-mysql -j2
```
- 编译成功后，dacd 程序在 build 目录下
