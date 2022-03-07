#-----------------------------------------------------------------------------+
#    添加 FetchContent 支持
#------------------------------------------------------------------------------
Include(FetchContent)


#-----------------------------------------------------------------------------+
#    Fetch Catch2
#------------------------------------------------------------------------------
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)


#-----------------------------------------------------------------------------+
#    单元测试程序
#------------------------------------------------------------------------------
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

link_directories(
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)

add_executable(
    FantasiaUnitTester ${srcs}
)

target_link_libraries(
    FantasiaUnitTester
    PRIVATE "Fantasia.Runtime" Catch2::Catch2WithMain
)


#-----------------------------------------------------------------------------+
#    Catch2 测试
#------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
#catch_discover_tests(FantasiaUnitTester)