# CMakeList.txt: runtime 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.22)

#-----------------------------------------------------------------------------+
#    Config c++ standard
#------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB_RECURSE src "${CMAKE_CURRENT_SOURCE_DIR}/../Fantasia/*")
message(${src})


# 将源代码添加到此项目的可执行文件。
add_executable ("Fantasia.Runtime" "Runtime.cpp" ${src})

# TODO: 如有需要，请添加测试并安装目标。
