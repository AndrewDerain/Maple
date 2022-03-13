
#-----------------------------------------------------------------------------+
#    Config project name.
#------------------------------------------------------------------------------
project(UnitTester)


#-----------------------------------------------------------------------------+
#    添加 FetchContent 支持
#------------------------------------------------------------------------------
Include(FetchContent)

set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/FetchedContent")


#-----------------------------------------------------------------------------+
#    Fetch Catch2
#------------------------------------------------------------------------------
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

message("-- [Note] Fetching Catch2 library.")
FetchContent_MakeAvailable(Catch2)

#-----------------------------------------------------------------------------+
#    单元测试程序
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

link_directories(
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)

link_libraries(
    "Fantasia.Runtime" Catch2::Catch2WithMain
)

add_executable(
    FantasiaUnitTester ${srcs}
)


#-----------------------------------------------------------------------------+
#    Catch2 测试
#------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
#catch_discover_tests(FantasiaUnitTester)
