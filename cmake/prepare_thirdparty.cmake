

add_custom_target(
    Thirdparty

    COMMAND ${CMAKE_COMMAND}    --install-prefix    "${fantasia_third_party_dir}"
                                -S                  "${fantasia_third_party_cmake_source_dir}/Catch2"
                                -B                  "${fantasia_third_party_cmake_binary_dir}/Catch2"
    COMMAND ${CMAKE_COMMAND}    --build             "${fantasia_third_party_cmake_binary_dir}/Catch2"
    COMMAND ${CMAKE_COMMAND}    --install           "${fantasia_third_party_cmake_binary_dir}/Catch2"
)


set(Catch2_DIR "${fantasia_third_party_dir}/lib/cmake/Catch2")