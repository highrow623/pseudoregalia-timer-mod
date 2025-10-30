cmake_minimum_required(VERSION 3.18)

set(TARGET PseudoCustomTTMod)
project(${TARGET})

add_library(${TARGET} SHARED
    "dllmain.cpp"
    "src/Logger.cpp"
    "src/ModHooks.cpp"
)

target_include_directories(${TARGET} PRIVATE "include")
target_link_libraries(${TARGET} PUBLIC UE4SS)
