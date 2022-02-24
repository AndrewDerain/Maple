
# Fantasia Framework 

> 幻曲 C++ 开发框架


## 这是SHA？

这个项目是我自己学习 C++ 的一个实践项目，以个人的喜好打造的，从基本的数据（包括 Int64，Float64，IPC 等等）开始构建的一个 C++ 开发框架。

Fantasia（幻曲）' . '， 这个名字意味着这个库可能永远也不会真正完成。这个库的第一个版本（1.0）也并没有计划的完成时间以及会包含多少东西 -_-


## 目录结构

|类型| 文件夹| 说明 | Git 管理 |
|----|------|------|:----------:|
|文件夹|.buildcache|cmake 配置缓存|无，CMake自动生成|
|文件夹|.vscode|Visual Studio Code 配置文件|有|
|文件夹|Compiled|此项目生成的可执行文件和库文件|无|
|文件夹|Install|此项目的cmake安装目录|无|
|文件夹|Include|对外提供的包含目录|有|
|文件夹|Source|源代码|有|
|文件夹|UnitTest|单元测试|有|
||||


## 和几个文件

|类型| 文件| 说明 |
|------|-------|-----------------|
|markdown|[readme.md](readme.md)|项目概览说明文件
|CMake|[CMakeLists.txt](CMakeLists.txt)|顶层 CMake 项目管理文件
|CMake|[CMakeSettings.json](CMakeSettings.json)|Visual Studio CMake 项目配置文件
||||


## 编译之前
- 此项目需要 C++ 20 及以上的版本
- 此项目需要 CMake 3.20 及以上的版本


## 编译项目
- Linux 环境
    - [Ubuntu 20.04 LTS](Documents/CompileOnUbuntu.md)

## 参考
[代码原则](Documents/CodeConcept.md)

---
> 仅以此项目，献给一直支持和鼓励我的韦女士 :)
