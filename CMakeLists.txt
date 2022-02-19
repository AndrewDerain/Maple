#-----------------------------------------------------------------------------+
# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
#------------------------------------------------------------------------------


#-----------------------------------------------------------------------------+
#     Config CMake Minimum Version
#------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.20)


#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project (
	"Fantasia"
	VERSION 1.0.0.0
	DESCRIPTION "Morden C++ & for fun")


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
set(CompileFolderPrefix "Compiled")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
	"${CMAKE_SOURCE_DIR}/${CompileFolderPrefix}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 
	"${CMAKE_SOURCE_DIR}/${CompileFolderPrefix}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	"${CMAKE_SOURCE_DIR}/${CompileFolderPrefix}")


#-----------------------------------------------------------------------------+
#    Config common include folders
#------------------------------------------------------------------------------
include_directories(
	"${CMAKE_SOURCE_DIR}/Include")


#-----------------------------------------------------------------------------+
#    Config subprojects
#------------------------------------------------------------------------------
add_subdirectory("Source/Runtime")
add_subdirectory("UnitTest")
