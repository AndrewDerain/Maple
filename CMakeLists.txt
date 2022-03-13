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
	Fantasia
	VERSION 1.0.0.0
	DESCRIPTION "Morden C++ Framework")


#-----------------------------------------------------------------------------+
#    Config c++ standard
#------------------------------------------------------------------------------
enable_language(CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#-----------------------------------------------------------------------------+
#    Config compiler 
#------------------------------------------------------------------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options(/Zc:preprocessor)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	SET(CMAKE_CXX_COMPILER "g++-11")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
endif()


#-----------------------------------------------------------------------------+
#    Config compile options
#------------------------------------------------------------------------------
if(CMAKE_GENERATOR MATCHES "^(Xcode|Visual Studio)")
	set(CompileFolderPrefix "Compiled/${CMAKE_GENERATOR}")
	message("-- [DBG] ${CompileFolderPrefix}")
else()
	set(CompileFolderPrefix "Compiled/${CMAKE_GENERATOR}/${CMAKE_BUILD_TYPE}")
endif()

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
add_subdirectory("Source")
add_subdirectory("UnitTest")
