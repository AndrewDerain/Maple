
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	CommandExecutor
	VERSION 1.0.0.0
	DESCRIPTION "Morden C++ Framework Commandline executor")


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")


#-----------------------------------------------------------------------------+
#    配置项目输出库文件
#------------------------------------------------------------------------------
add_executable(vint ${srcs})

set_target_properties(
    vint 
    PROPERTIES 
    CXX_VISIBILITY_PRESET      hidden
    VISIBILITY_INLINES_HIDDEN  ON
)
