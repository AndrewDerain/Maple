# CMakeList.txt: runtime 的 CMake 项目，在此处包括源代码并定义


file(GLOB_RECURSE incs "${CMAKE_CURRENT_SOURCE_DIR}/../../Fantasia/")
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_executable ("Fantasia.Runtime.Lancher" ${srcs} ${incs})
add_library("Fantasia.Runtime" SHARED ${srcs} ${incs})
