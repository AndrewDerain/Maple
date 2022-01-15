
file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/*")

link_directories("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
link_libraries("Fantasia.Runtime")
add_executable ("Fantasia.Test" ${srcs})
