
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	CommandlineExecutor
	VERSION 1.0.0.0
	DESCRIPTION "Modern C++ Framework Commandline executor")


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")


#-----------------------------------------------------------------------------+
#    配置项目输出库文件
#------------------------------------------------------------------------------
set(target_name "maple")

link_directories(
    "${fantasia_library_out_dir}"
)

link_libraries(
    "Maple.Runtime"
)

add_executable(
    ${target_name} ${srcs}
)

set_target_properties(
    ${target_name} 
    PROPERTIES 
    
    CXX_VISIBILITY_PRESET      hidden
    VISIBILITY_INLINES_HIDDEN  ON
)


#-----------------------------------------------------------------------------+
#    项目安装配置
#------------------------------------------------------------------------------
install(TARGETS ${target_name})
