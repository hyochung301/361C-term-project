cmake_minimum_required(VERSION 3.10)
set(CMAKE_CUDA_ARCHITECTURES 75)
project(termproj LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(fluid-solver-toy/lib/flgl)
add_subdirectory(fluid-solver-toy/lib/fftw)

include_directories(${PROJECT_SOURCE_DIR}/fluid-solver-toy/lib/flgl/inc)
include_directories(${PROJECT_SOURCE_DIR}/fluid-solver-toy/lib/flgl/lib/glm)
include_directories(${PROJECT_SOURCE_DIR}/fluid-solver-toy/lib/fftw/inc)
include_directories(${PROJECT_SOURCE_DIR}/fluid-solver-toy/lib/sw)
include_directories(${PROJECT_SOURCE_DIR}/fluid-solver-toy/src)

file(GLOB_RECURSE PROJECT_SOURCES "fluid-solver-toy/lib/sw/*.cpp" "fluid-solver-toy/src/*.cpp" "src/*.cpp")
file(GLOB_RECURSE PROJECT_CUDA_SOURCES "src/*.cu")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_CUDA_SOURCES})

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)

target_link_libraries(${PROJECT_NAME} FLGL)

target_link_libraries(${PROJECT_NAME} fftw3)

# if (WIN32)
#   set(FFTW_NAME fftw3w)
# else()
#   set(FFTW_NAME fftw3)
# endif()

# find_library(FFTW
#              NAMES ${FFTW_NAME}
#              HINTS /usr/local/lib fluid-solver-toy/lib/fftw/bin
#              )

# if(FFTW)
#     message("FFTW found")
#     target_link_libraries(${PROJECT_NAME} ${FFTW})
# else()
#     message(FATAL_ERROR "FFTW library not found")
# endif()
