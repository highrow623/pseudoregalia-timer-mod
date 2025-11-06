cmake_minimum_required(VERSION 3.18)

set(TARGET PseudoregaliaTimerMod)
project(${TARGET})

add_library(${TARGET} SHARED
    "dllmain.cpp"
    "src/Event.cpp"
    "src/Logger.cpp"
    "src/ModHooks.cpp"
    "src/Trigger.cpp"
)

target_include_directories(${TARGET} PRIVATE "include")
target_link_libraries(${TARGET} PUBLIC UE4SS)
