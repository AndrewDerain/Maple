
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project(UnitTester)


#-----------------------------------------------------------------------------+
#    引用第三方库
#------------------------------------------------------------------------------
find_package(Catch2 3 REQUIRED)


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")


#-----------------------------------------------------------------------------+
#    单元测试程序
#------------------------------------------------------------------------------
set(target_name_unit_test "ut${fantasia_target_postfix}")

include_directories(
    "${fantasia_third_party_dir}/include"
)

link_directories(
    "${fantasia_library_out_dir}"
    "${fantasia_third_party_dir}/lib"
)

link_libraries(
    "Fantasia.Runtime${fantasia_target_postfix}" "Catch2::Catch2WithMain"
)

add_executable(
    ${target_name_unit_test} ${srcs}
)

set_target_properties(
    ${target_name_unit_test}
    PROPERTIES

    CXX_VISIBILITY_PRESET               hidden
    VISIBILITY_INLINES_HIDDEN           ON
)
#add_executable(ExpAttr "Runtime/ExpAttr.cxx")


#-----------------------------------------------------------------------------+
#    Catch2 测试
#------------------------------------------------------------------------------
#include(CTest)
#include(Catch)
#catch_discover_tests(FantasiaUnitTester)
