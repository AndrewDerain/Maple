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
    DESCRIPTION "Modern C++ Framework")


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


#-----------------------------------------------------------------------------+
#    Config global config
#------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG            "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE          "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL       "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO   "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG            "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE          "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL       "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO   "${CMAKE_SOURCE_DIR}/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG            "${CMAKE_SOURCE_DIR}/archive")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE          "${CMAKE_SOURCE_DIR}/archive")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL       "${CMAKE_SOURCE_DIR}/archive")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO   "${CMAKE_SOURCE_DIR}/archive")

set(fantasia_third_party_dir                 "${CMAKE_SOURCE_DIR}/thirdparty")
set(fantasia_third_party_cmake_source_dir    "${CMAKE_SOURCE_DIR}/thirdparty/src")
set(fantasia_third_party_cmake_binary_dir    "${CMAKE_BINARY_DIR}/thirdparty/src")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(fantasia_target_postfix "-d")
else()
    set(fantasia_target_postfix "")
endif()


#-----------------------------------------------------------------------------+
#    Config global include folders
#------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include")


#-----------------------------------------------------------------------------+
#    Config global rpath
#------------------------------------------------------------------------------
set(CMAKE_INSTALL_RPATH ".:../lib")
set(CMAKE_BUILD_RPATH   ".:../lib")


#-----------------------------------------------------------------------------+
#    Config subprojects
#------------------------------------------------------------------------------
add_subdirectory("src")
add_subdirectory("ut")
