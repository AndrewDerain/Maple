﻿
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project(UnitTester)


#-----------------------------------------------------------------------------+
#    引用第三方库
#------------------------------------------------------------------------------
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/**")


#-----------------------------------------------------------------------------+
#    单元测试程序
#------------------------------------------------------------------------------
set(target_name_unit_test "ut${fantasia_target_postfix}")

link_libraries(
    "Maple.Runtime${fantasia_target_postfix}"
    "Catch2::Catch2WithMain"
)

add_executable(
    ${target_name_unit_test} ${srcs}
)
