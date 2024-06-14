cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

project(example C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/Blinky)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/RTOSHooks)

pico_sdk_init()

add_library(Application INTERFACE)
target_sources(Application INTERFACE
        main.c)
target_include_directories(Application INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_SOURCE_DIR}/includes
)
target_link_libraries(Application INTERFACE
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        pico_stdlib
        hardware_timer
        Blinky)

add_executable(App)
target_link_libraries(App Application RTOSHooks)
target_compile_options(App PRIVATE -Wall)
pico_add_extra_outputs(App)
pico_enable_stdio_usb(App 1)