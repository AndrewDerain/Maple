
# Ubuntu 20.04 LTS 环境配置和编译


**1. 如果 GCC 和 G++ 版本低于 11 先升级 GCC G++ 版本到 11**

- 添加工具链仓库：
```
    $ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    $ sudo apt update
```

- 安装 GCC11 G++11
```
    $ sudo apt install -y gcc-11 g++-11
```

**2. 安装 cmake**
```
    $ sudo apt install cmake
```
- 确认版本大于3.20
```
    $ cmake --version
    cmake version 3.22.2

    CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

**3. 安装其他组件**
```
    $ sudo apt install -y git
```

**4. 克隆仓库**
```
    $ mkdir ~/repo 
    $ cd repo
    $ git clone https://github.com/AndrewDerain/Fantasia.git
    $ cd Fantasia
```

**5. 创建 cmake build 缓存**
```
    $ cmake -S. -B.buildcache
```

**6. 编译项目，程序会在 Compiled 文件夹中生成**
```
    $ cmake --build .buildcache
```
