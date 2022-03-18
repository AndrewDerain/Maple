
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	Runtime
	VERSION 1.0.0.0
	DESCRIPTION "Morden C++ Framework Runtime")


#-----------------------------------------------------------------------------+
#    配置预处理器
#------------------------------------------------------------------------------
add_compile_definitions(___FNATASIA_EXPORTS)


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../Include/*")


#-----------------------------------------------------------------------------+
#    配置项目输出库文件
#------------------------------------------------------------------------------
set(target_name_runtime "Fantasia.Runtime")

add_library(${target_name_runtime} SHARED ${srcs})

set_target_properties(
    ${target_name_runtime}
    PROPERTIES 
    CXX_VISIBILITY_PRESET               hidden
    VISIBILITY_INLINES_HIDDEN           ON
    LIBRARY_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL     "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/lib"
)


#-----------------------------------------------------------------------------+
#    项目安装配置
#------------------------------------------------------------------------------
