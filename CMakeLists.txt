#-----------------------------------------------------------------------------+
# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
#------------------------------------------------------------------------------


#-----------------------------------------------------------------------------+
#     Config CMake Minimum Version
#------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.22)


#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	"Fantasia"
	VERSION 1.0.0.0
	DESCRIPTION "纯粹为了自己好玩")


#-----------------------------------------------------------------------------+
#    Config c++ standard
#------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#-----------------------------------------------------------------------------+
#    Config compile options
#------------------------------------------------------------------------------
if(MSVC)
	add_compile_options(/Zc:preprocessor)
endif()


#-----------------------------------------------------------------------------+
#    Config compile options
#------------------------------------------------------------------------------

message("CMAKE_SYSTEM = ${APPLE}")

set(CompileFolderPrefix "Compile.${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
	"${CMAKE_SOURCE_DIR}/${CompileFolderPrefix}.Bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 
	"${CMAKE_SOURCE_DIR}/${CompileFolderPrefix}.Lib")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Include/")

# 包含子项目。
add_subdirectory("Source/Runtime")
add_subdirectory("UnitTest")
