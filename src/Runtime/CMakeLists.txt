
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	Runtime
	VERSION 1.0.0.0
	DESCRIPTION "Modern C++ Framework Runtime")


#-----------------------------------------------------------------------------+
#    配置预处理器
#------------------------------------------------------------------------------
add_compile_definitions(___MAPLE_RUNTIME_EXPORTS)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_compile_definitions(___MAPLE_RUNTIME_DEBUG)
endif()


#-----------------------------------------------------------------------------+
#    代码覆盖率
#------------------------------------------------------------------------------
if((CMAKE_BUILD_TYPE STREQUAL "Debug") AND (CMAKE_GENERATOR STREQUAL Ninja))
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage ")
	#set(CMAKE_C_FLAGS "{CMAKE_C_FLAGS} --coverage ")
endif()


#-----------------------------------------------------------------------------+
#    配置源代码文件
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

file(GLOB_RECURSE hdrs 
	"${CMAKE_SOURCE_DIR}/include/Maple/Runtime.hxx" 
	"${CMAKE_SOURCE_DIR}/include/Maple/Runtime/*")


#-----------------------------------------------------------------------------+
#    配置项目输出库文件
#------------------------------------------------------------------------------
set(target_name "Maple.Runtime${fantasia_target_postfix}")

add_library(${target_name} SHARED ${srcs} ${hdrs})
 
set_target_properties(
    ${target_name}
    PROPERTIES 
    
    CXX_VISIBILITY_PRESET		hidden
    VISIBILITY_INLINES_HIDDEN 	ON
)


#-----------------------------------------------------------------------------+
#    项目安装配置
#------------------------------------------------------------------------------
install(TARGETS ${target_name})
install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/Maple/Runtime" DESTINATION "include/Maple/Runtime")
