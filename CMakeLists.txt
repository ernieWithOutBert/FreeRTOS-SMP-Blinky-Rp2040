cmake_minimum_required(VERSION 3.13)

# Initialise the external dependencies
include(FetchContent)

Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  FreeRTOS-Kernel
  SOURCE_DIR "../external/FreeRTOS-Kernel"
  GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
  GIT_TAG V11.1.0
  GIT_SUBMODULES_RECURSE TRUE
  GIT_PROGRESS TRUE
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
)

FetchContent_Declare(
  pico-sdk
  SOURCE_DIR "../external/pico-sdk"
  GIT_REPOSITORY https://github.com/raspberrypi/pico-sdk
  GIT_TAG 1.5.1
  GIT_SUBMODULES_RECURSE TRUE
  GIT_PROGRESS TRUE
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
)

FetchContent_Declare(
  pico_extras
  SOURCE_DIR "../external/pico_extras"
  GIT_REPOSITORY https://github.com/raspberrypi/pico-extras
  GIT_TAG master
  GIT_SUBMODULES_RECURSE TRUE
  GIT_PROGRESS TRUE
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
)

if(EXISTS "../external/pico-sdk")
  message("pico-sdk does exist under ../external/pico-sdk ")
else()
  FetchContent_GetProperties(pico-sdk)

  if(NOT pico-sdk_POPULATED)
    message("Downloading pico-sdk...")
    FetchContent_Populate(pico-sdk)
    add_subdirectory(../external/${pico-sdk_SOURCE_DIR} ${pico-sdk_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()

  message("pico-sdk  has been downloaded")
endif()

set(PICO_SDK_PATH "../external/pico-sdk")

if(EXISTS "../external/pico_extras")
  message("pico extras does exist under ../external/pico_extras ")
else()
  FetchContent_GetProperties(pico_extras)

  if(NOT pico_extras_POPULATED)
    message("Downloading pico extras...")
    FetchContent_Populate(pico_extras)
    add_subdirectory(../external/${pico_extras_SOURCE_DIR} ${pico_extras_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()

  message("pico_extras  has been downloaded")
endif()

set(PICO_EXTRA_PATH "../external/pico_extras")

if(EXISTS "../external/FreeRTOS-Kernel")
  message("FreeRTOS-Kernel does exist under ../external/FreeRTOS-Kernel")
else()
  Set(FETCHCONTENT_QUIET FALSE)
  FetchContent_GetProperties(FreeRTOS-Kernel)

  if(NOT FreeRTOS-Kernel_POPULATED)
    message("Downloading FreeRTOS Kernel...")
    FetchContent_Populate(FreeRTOS-Kernel)
    add_subdirectory(../external/${freertos-kernel_SOURCE_DIR} ${freertos-kernel_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()

  message("FreeRTOS-Kernel has been downloaded")
endif()

set(FREERTOS_KERNEL_PATH "../external/FreeRTOS-Kernel")

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(Application C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") Debug symbols in the elf file
add_subdirectory(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/includes)
