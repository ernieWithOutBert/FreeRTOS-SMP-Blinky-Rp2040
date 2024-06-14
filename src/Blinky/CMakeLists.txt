cmake_minimum_required(VERSION 3.13)

add_library(Blinky STATIC BlinkyCore1.c BlinkyCore0.c)

target_include_directories(Blinky INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
    ${FREERTOS_KERNEL_PATH}/includes
    ${PICO_SDK_PATH}
)
include_directories(${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(Blinky Application)
