
# Ubuntu 20.04 LTS 环境配置和编译


**1. 如果 GCC 和 G++ 版本低于 10 先升级 GCC G++ 版本到 10**

- 安装 GCC10 和 G++10
```bash
    $ sudo apt install -y gcc-10 g++-10
```

- 修改 cmake 的环境变量
```bash
    $ export CC=/bin/gcc-10
    $ export CXX=/bin/g++-10
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

**5. 更新依赖的子模块**
```
    $ python3 ./init_thirdparty.py
```

**6. 创建 cmake build 缓存**
```
    $ cmake --preset="Unix.Release" .
```

**7. 编译项目，程序会在 `bin` `lib` 文件夹中生成**
```
    $ cmake --build --preset="Unix.Release.All"
```
