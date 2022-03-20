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
	VERSION 0.0.0.0
	DESCRIPTION "Morden C++ Framework")


#-----------------------------------------------------------------------------+
#    Config c++ standard
#------------------------------------------------------------------------------
enable_language(CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#-----------------------------------------------------------------------------+
#    Config compiler settings
#------------------------------------------------------------------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options(/Zc:preprocessor /ZI /INCREMENTAL)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
endif()


#-----------------------------------------------------------------------------+
#    Config golbal config
#------------------------------------------------------------------------------
set(fantasia_runtime_out_dir 	"${CMAKE_SOURCE_DIR}/bin")
set(fantasia_library_out_dir 	"${CMAKE_SOURCE_DIR}/lib")
set(fantasia_archive_out_dir 	"${CMAKE_SOURCE_DIR}/lib")

set(fantasia_third_party_dir				"${CMAKE_SOURCE_DIR}/thirdparty")
set(fantasia_third_party_cmake_source_dir	"${CMAKE_SOURCE_DIR}/thirdparty/src")
set(fantasia_third_party_cmake_binary_dir	"${CMAKE_BINARY_DIR}/thirdparty/src")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(fantasia_target_postfix "d")
else()
	set(fantasia_target_postfix "")
endif()

#-----------------------------------------------------------------------------+
#    Config global include folders
#------------------------------------------------------------------------------
include_directories(
	"${CMAKE_SOURCE_DIR}/include")


#-----------------------------------------------------------------------------+
#    Config golbal rpath
#------------------------------------------------------------------------------
set(CMAKE_INSTALL_RPATH ".:../lib")
set(CMAKE_BUILD_RPATH	".:../lib")


#-----------------------------------------------------------------------------+
#    Config third party libraries
#------------------------------------------------------------------------------
include(cmake/prepare_thirdparty.cmake)


#-----------------------------------------------------------------------------+
#    Config subprojects
#------------------------------------------------------------------------------
add_subdirectory("src")
add_subdirectory("ut")
