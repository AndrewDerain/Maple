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
    add_compile_options(/Zc:preprocessor /Zi /INCREMENTAL)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    #[[add_compile_options("-fmodules")]]
endif ()


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

set(RCLH "[Root] -- ")

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


#-----------------------------------------------------------------------------+
#    Configured variables
#------------------------------------------------------------------------------
message(${RCLH} CMAKE_ROOT = ${CMAKE_ROOT})
message(${RCLH} CMAKE_BUILD_TYPE         = ${CMAKE_BUILD_TYPE})
message(${RCLH} CMAKE_CXX_COMPILER_ID    = ${CMAKE_CXX_COMPILER_ID})
message(${RCLH} CMAKE_GENERATOR_PLATFORM = ${CMAKE_GENERATOR_PLATFORM})


message(${RCLH})
message(${RCLH} "----------------------------------")
message(${RCLH} "Variables that Describe the System")
message(${RCLH} "ANDROID        = ${ANDROID}")
message(${RCLH} "APPLE          = ${APPLE}")
message(${RCLH} "BORLAND        = ${BORLAND}")
message(${RCLH})
message(${RCLH} "CMAKE_ANDROID_NDK_VERSION  = ${CMAKE_ANDROID_NDK_VERSION}")
message(${RCLH} "CMAKE_CL_64                = ${CMAKE_CL_64}")
message(${RCLH} "CMAKE_COMPILER_2005        = ${CMAKE_COMPILER_2005}")
message(${RCLH})
message(${RCLH} "CMAKE_HOST_SYSTEM              = ${CMAKE_HOST_SYSTEM}")
message(${RCLH} "CMAKE_HOST_SYSTEM_NAME         = ${CMAKE_HOST_SYSTEM_NAME}")
message(${RCLH} "CMAKE_HOST_SYSTEM_PROCESSOR    = ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(${RCLH} "CMAKE_HOST_SYSTEM_VERSION      = ${CMAKE_HOST_SYSTEM_VERSION}")
message(${RCLH} "CMAKE_HOST_APPLE       = ${CMAKE_HOST_APPLE}")
message(${RCLH} "CMAKE_HOST_SOLARIS     = ${CMAKE_HOST_SOLARIS}")
message(${RCLH} "CMAKE_HOST_UNIX        = ${CMAKE_HOST_UNIX}")
message(${RCLH} "CMAKE_HOST_WIN32       = ${CMAKE_HOST_WIN32}")
message(${RCLH})
message(${RCLH} "CMAKE_LIBRARY_ARCHITECTURE         = ${CMAKE_LIBRARY_ARCHITECTURE}")
message(${RCLH} "CMAKE_LIBRARY_ARCHITECTURE_REGEX   = ${CMAKE_LIBRARY_ARCHITECTURE_REGEX}")
message(${RCLH} "CMAKE_OBJECT_PATH_MAX              = ${CMAKE_OBJECT_PATH_MAX}")
message(${RCLH})
message(${RCLH} "CMAKE_SYSTEM           = ${CMAKE_SYSTEM}")
message(${RCLH} "CMAKE_SYSTEM_NAME      = ${CMAKE_SYSTEM_NAME}")
message(${RCLH} "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
message(${RCLH} "CMAKE_SYSTEM_VERSION   = ${CMAKE_SYSTEM_VERSION}")
message(${RCLH})
message(${RCLH} "CYGWIN     = ${CYGWIN}")
message(${RCLH} "GHSMULTI   = ${GHSMULTI}")
message(${RCLH} "IOS        = ${IOS}")
message(${RCLH} "MINGW      = ${MINGW}")
message(${RCLH} "MSVC       = ${MSVC}")
message(${RCLH} "MSVC10     = ${MSVC10}")
message(${RCLH} "MSVC11     = ${MSVC11}")
message(${RCLH} "MSVC12     = ${MSVC12}")
message(${RCLH} "MSVC14     = ${MSVC14}")
message(${RCLH} "MSVC60     = ${MSVC60}")
message(${RCLH} "MSVC70     = ${MSVC70}")
message(${RCLH} "MSVC71     = ${MSVC71}")
message(${RCLH} "MSVC80     = ${MSVC80}")
message(${RCLH} "MSVC90     = ${MSVC90}")
message(${RCLH} "MSVC_IDE               = ${MSVC_IDE}")
message(${RCLH} "MSVC_TOOLSET_VERSION   = ${MSVC_TOOLSET_VERSION}")
message(${RCLH} "MSVC_VERSION           = ${MSVC_VERSION}")
message(${RCLH} "MSYS           = ${MSYS}")
message(${RCLH} "UNIX           = ${UNIX}")
message(${RCLH} "WIN32          = ${WIN32}")
message(${RCLH} "WINCE          = ${WINCE}")
message(${RCLH} "WINDOWS_PHONE  = ${WINDOWS_PHONE}")
message(${RCLH} "WINDOWS_STORE  = ${WINDOWS_STORE}")
message(${RCLH} "XCODE          = ${XCODE}")
message(${RCLH} "XCODE_VERSION  = ${XCODE_VERSION}")

message(${RCLH})
message(${RCLH} "----------------------------------")
message(${RCLH} "Variables that Change Behavior")

message(${RCLH} "BUILD_SHARED_LIBS                  = ${BUILD_SHARED_LIBS}")
message(${RCLH} "CMAKE_ABSOLUTE_DESTINATION_FILES   = ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
message(${RCLH} "CMAKE_APPBUNDLE_PATH               = ${CMAKE_APPBUNDLE_PATH}")
message(${RCLH} "CMAKE_AUTOMOC_RELAXED_MODE         = ${CMAKE_AUTOMOC_RELAXED_MODE}")
message(${RCLH} "CMAKE_BACKWARDS_COMPATIBILITY      = ${CMAKE_BACKWARDS_COMPATIBILITY}")
message(${RCLH} "CMAKE_DEPENDS_IN_PROJECT_ONLY      = ${CMAKE_DEPENDS_IN_PROJECT_ONLY}")
message(${RCLH})
message(${RCLH} "CMAKE_BUILD_TYPE           = ${CMAKE_BUILD_TYPE}")
message(${RCLH} "CMAKE_CONFIGURATION_TYPES  = ${CMAKE_CONFIGURATION_TYPES}")
message(${RCLH})
message(${RCLH} "CMAKE_FRAMEWORK_PATH       = ${CMAKE_FRAMEWORK_PATH}")
message(${RCLH} "CMAKE_IGNORE_PATH          = ${CMAKE_IGNORE_PATH}")
message(${RCLH} "CMAKE_IGNORE_PREFIX_PATH   = ${CMAKE_IGNORE_PREFIX_PATH}")
message(${RCLH})
message(${RCLH} "CMAKE_INCLUDE_DIRECTORIES_BEFORE               = ${CMAKE_INCLUDE_DIRECTORIES_BEFORE}")
message(${RCLH} "CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE       = ${CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE}")
message(${RCLH} "CMAKE_INCLUDE_PATH                             = ${CMAKE_INCLUDE_PATH}")
message(${RCLH} "CMAKE_INSTALL_DEFAULT_COMPONENT_NAME           = ${CMAKE_INSTALL_DEFAULT_COMPONENT_NAME}")
message(${RCLH} "CMAKE_INSTALL_DEFAULT_DIRECTORY_PERMISSIONS    = ${CMAKE_INSTALL_DEFAULT_DIRECTORY_PERMISSIONS}")
message(${RCLH} "CMAKE_INSTALL_MESSAGE                          = ${CMAKE_INSTALL_MESSAGE}")
message(${RCLH} "CMAKE_INSTALL_PREFIX                           = ${CMAKE_INSTALL_PREFIX}")
message(${RCLH} "CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT    = ${CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT}")
message(${RCLH} "CMAKE_LIBRARY_PATH                             = ${CMAKE_LIBRARY_PATH}")
message(${RCLH} "CMAKE_LINK_DIRECTORIES_BEFORE                  = ${CMAKE_LINK_DIRECTORIES_BEFORE}")
message(${RCLH} "CMAKE_LINK_LIBRARIES_ONLY_TARGETS              = ${CMAKE_LINK_LIBRARIES_ONLY_TARGETS}")
message(${RCLH})
message(${RCLH} "CMAKE_MODULE_PATH               = ${CMAKE_MODULE_PATH}")
message(${RCLH} "CMAKE_PREFIX_PATH               = ${CMAKE_PREFIX_PATH}")
message(${RCLH} "CMAKE_PROGRAM_PATH              = ${CMAKE_PROGRAM_PATH}")
message(${RCLH} "CMAKE_PROJECT_INCLUDE           = ${CMAKE_PROJECT_INCLUDE}")
message(${RCLH} "CMAKE_PROJECT_INCLUDE_BEFORE    = ${CMAKE_PROJECT_INCLUDE_BEFORE}")
message(${RCLH} "CMAKE_SUPPRESS_REGENERATION     = ${CMAKE_SUPPRESS_REGENERATION}")
message(${RCLH} "CMAKE_SYSROOT                   = ${CMAKE_SYSROOT}")
message(${RCLH} "CMAKE_SYSROOT_COMPILE           = ${CMAKE_SYSROOT_COMPILE}")
message(${RCLH} "CMAKE_SYSROOT_LINK              = ${CMAKE_SYSROOT_LINK}")
message(${RCLH} "CMAKE_SYSTEM_APPBUNDLE_PATH     = ${CMAKE_SYSTEM_APPBUNDLE_PATH}")
message(${RCLH} "CMAKE_SYSTEM_FRAMEWORK_PATH     = ${CMAKE_SYSTEM_FRAMEWORK_PATH}")
message(${RCLH} "CMAKE_SYSTEM_IGNORE_PATH        = ${CMAKE_SYSTEM_IGNORE_PATH}")
message(${RCLH} "CMAKE_SYSTEM_IGNORE_PREFIX_PATH = ${CMAKE_SYSTEM_IGNORE_PREFIX_PATH}")
message(${RCLH} "CMAKE_SYSTEM_INCLUDE_PATH       = ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(${RCLH} "CMAKE_SYSTEM_LIBRARY_PATH       = ${CMAKE_SYSTEM_LIBRARY_PATH}")
message(${RCLH} "CMAKE_SYSTEM_PREFIX_PATH        = ${CMAKE_SYSTEM_PREFIX_PATH}")
message(${RCLH} "CMAKE_SYSTEM_PROGRAM_PATH       = ${CMAKE_SYSTEM_PROGRAM_PATH}")
message(${RCLH} "CMAKE_TLS_CAINFO                = ${CMAKE_TLS_CAINFO}")
message(${RCLH} "CMAKE_TLS_VERIFY                = ${CMAKE_TLS_VERIFY}")
message(${RCLH} "CMAKE_USER_MAKE_RULES_OVERRIDE  = ${CMAKE_USER_MAKE_RULES_OVERRIDE}")
message(${RCLH} "CMAKE_WARN_DEPRECATED           = ${CMAKE_WARN_DEPRECATED}")
message(${RCLH} "CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION = ${CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION}")
message(${RCLH})
message(${RCLH} "CMAKE_XCODE_GENERATE_SCHEME                            = ${CMAKE_XCODE_GENERATE_SCHEME}")
message(${RCLH} "CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY            = ${CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY}")
message(${RCLH} "CMAKE_XCODE_LINK_BUILD_PHASE_MODE                      = ${CMAKE_XCODE_LINK_BUILD_PHASE_MODE}")
message(${RCLH} "CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER                   = ${CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER}")
message(${RCLH} "CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN  = ${CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN}")
message(${RCLH} "CMAKE_XCODE_SCHEME_DEBUG_DOCUMENT_VERSIONING           = ${CMAKE_XCODE_SCHEME_DEBUG_DOCUMENT_VERSIONING}")
message(${RCLH} "CMAKE_XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE       = ${CMAKE_XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE}")
message(${RCLH} "CMAKE_XCODE_SCHEME_DISABLE_MAIN_THREAD_CHECKER         = ${CMAKE_XCODE_SCHEME_DISABLE_MAIN_THREAD_CHECKER}")
message(${RCLH} "CMAKE_XCODE_SCHEME_DYNAMIC_LIBRARY_LOADS               = ${CMAKE_XCODE_SCHEME_DYNAMIC_LIBRARY_LOADS}")
message(${RCLH} "CMAKE_XCODE_SCHEME_DYNAMIC_LINKER_API_USAGE            = ${CMAKE_XCODE_SCHEME_DYNAMIC_LINKER_API_USAGE}")
message(${RCLH} "CMAKE_XCODE_SCHEME_ENVIRONMENT                         = ${CMAKE_XCODE_SCHEME_ENVIRONMENT}")
message(${RCLH} "CMAKE_XCODE_SCHEME_GUARD_MALLOC                        = ${CMAKE_XCODE_SCHEME_GUARD_MALLOC}")
message(${RCLH} "CMAKE_XCODE_SCHEME_MAIN_THREAD_CHECKER_STOP            = ${CMAKE_XCODE_SCHEME_MAIN_THREAD_CHECKER_STOP}")
message(${RCLH} "CMAKE_XCODE_SCHEME_MALLOC_GUARD_EDGES                  = ${CMAKE_XCODE_SCHEME_MALLOC_GUARD_EDGES}")
message(${RCLH} "CMAKE_XCODE_SCHEME_MALLOC_SCRIBBLE                     = ${CMAKE_XCODE_SCHEME_MALLOC_SCRIBBLE}")
message(${RCLH} "CMAKE_XCODE_SCHEME_MALLOC_STACK                        = ${CMAKE_XCODE_SCHEME_MALLOC_STACK}")
message(${RCLH} "CMAKE_XCODE_SCHEME_THREAD_SANITIZER                    = ${CMAKE_XCODE_SCHEME_THREAD_SANITIZER}")
message(${RCLH} "CMAKE_XCODE_SCHEME_THREAD_SANITIZER_STOP               = ${CMAKE_XCODE_SCHEME_THREAD_SANITIZER_STOP}")
message(${RCLH} "CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER       = ${CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER}")
message(${RCLH} "CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER_STOP  = ${CMAKE_XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER_STOP}")
message(${RCLH} "CMAKE_XCODE_SCHEME_WORKING_DIRECTORY                   = ${CMAKE_XCODE_SCHEME_WORKING_DIRECTORY}")
message(${RCLH} "CMAKE_XCODE_SCHEME_ZOMBIE_OBJECTS                      = ${CMAKE_XCODE_SCHEME_ZOMBIE_OBJECTS}")
message(${RCLH} "CMAKE_XCODE_XCCONFIG                                   = ${CMAKE_XCODE_XCCONFIG}")

message(${RCLH})
message(${RCLH} "----------------------------------")
message(${RCLH} "Variables that Control the Build")
message(${RCLH} "CMAKE_APPLE_SILICON_PROCESSOR = ${CMAKE_APPLE_SILICON_PROCESSOR}")
message(${RCLH} "CMAKE_BUILD_RPATH                  = ${CMAKE_BUILD_RPATH}")
message(${RCLH} "CMAKE_BUILD_RPATH_USE_ORIGIN       = ${CMAKE_BUILD_RPATH_USE_ORIGIN}")
message(${RCLH} "CMAKE_BUILD_WITH_INSTALL_NAME_DIR  = ${CMAKE_BUILD_WITH_INSTALL_NAME_DIR}")
message(${RCLH} "CMAKE_BUILD_WITH_INSTALL_RPATH     = ${CMAKE_BUILD_WITH_INSTALL_RPATH}")
message(${RCLH})
message(${RCLH} "CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY                 = ${CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY}")
message(${RCLH} "CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_DEBUG           = ${CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_DEBUG}")
message(${RCLH} "CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_RELEASE         = ${CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_RELEASE}")
message(${RCLH} "CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_MINSIZEREL      = ${CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_MINSIZEREL}")
message(${RCLH} "CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_RELWITHDEBINFO  = ${CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY_RELWITHDEBINFO}")
message(${RCLH})
message(${RCLH} "CMAKE_COMPILE_WARNING_AS_ERROR = ${CMAKE_COMPILE_WARNING_AS_ERROR}")
message(${RCLH} "CMAKE_DEBUG_POSTFIX            = ${CMAKE_DEBUG_POSTFIX}")
message(${RCLH} "CMAKE_RELEASE_POSTFIX          = ${CMAKE_RELEASE_POSTFIX}")
message(${RCLH} "CMAKE_MINSIZEREL_POSTFIX       = ${CMAKE_MINSIZEREL_POSTFIX}")
message(${RCLH} "CMAKE_RELWITHDEBINFO_POSTFIX   = ${CMAKE_RELWITHDEBINFO_POSTFIX}")
message(${RCLH} "CMAKE_CROSS_CONFIGS            = ${CMAKE_CROSS_CONFIGS}")
message(${RCLH} "CMAKE_CTEST_ARGUMENTS          = ${CMAKE_CTEST_ARGUMENTS}")
message(${RCLH} "CMAKE_DEFAULT_BUILD_TYPE       = ${CMAKE_DEFAULT_BUILD_TYPE}")
message(${RCLH} "CMAKE_DEFAULT_CONFIGS          = ${CMAKE_DEFAULT_CONFIGS}")
message(${RCLH} "CMAKE_DISABLE_PRECOMPILE_HEADERS   = ${CMAKE_DISABLE_PRECOMPILE_HEADERS}")
message(${RCLH} "CMAKE_DEPENDS_USE_COMPILER         = ${CMAKE_DEPENDS_USE_COMPILER}")
message(${RCLH} "CMAKE_ENABLE_EXPORTS               = ${CMAKE_ENABLE_EXPORTS}")
message(${RCLH} "CMAKE_EXE_LINKER_FLAGS             = ${CMAKE_EXE_LINKER_FLAGS}")
message(${RCLH} "CMAKE_EXE_LINKER_FLAGS_INIT        = ${CMAKE_EXE_LINKER_FLAGS_INIT}")
message(${RCLH} "CMAKE_FOLDER                       = ${CMAKE_FOLDER}")
message(${RCLH} "CMAKE_FRAMEWORK                    = ${CMAKE_FRAMEWORK}")
message(${RCLH} "CMAKE_GENERATOR = ${CMAKE_GENERATOR}")
