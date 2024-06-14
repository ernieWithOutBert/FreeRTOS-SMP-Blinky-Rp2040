cmake_minimum_required(VERSION 3.13)

add_library(RTOSHooks STATIC RTOSHooks.c)

target_include_directories(RTOSHooks INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
    ${FREERTOS_KERNEL_PATH}/includes
    ${PICO_SDK_PATH}
)
include_directories(${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(RTOSHooks Application)
