cmake_minimum_required(VERSION 3.9)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Check that interprocedural optimization is supported
include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORTED)
if(IPO_SUPPORTED AND CMAKE_BUILD_TYPE STREQUAL Release)
    set(IPO_ENABLED True)
else()
    set(IPO_ENABLED False)
endif()

# Check that -march=native is supported
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_OPT_ARCH_NATIVE_SUPPORTED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wno-unused-variable")

add_executable(ray_tracer
        include/camera.hpp
        include/color.hpp
        include/pixel.hpp
        include/ray.hpp
        include/rayTracerExceptions.hpp
        include/shape.hpp
        include/sphere.hpp
        include/vector_3d.hpp
        include/world.hpp
        src/camera.cpp
        src/color.cpp
        src/pixel.cpp
        src/ray.cpp
        src/shape.cpp
        src/sphere.cpp
        src/vector_3d.cpp
        src/world.cpp
        main.cpp)

target_include_directories(ray_tracer PRIVATE include)
target_compile_options(ray_tracer PRIVATE -Wall -Wextra -pedantic)

if (COMPILER_OPT_ARCH_NATIVE_SUPPORTED)
    target_compile_options(ray_tracer PRIVATE "-march=native")
endif()

if(IPO_ENABLED)
    set_property(TARGET ray_tracer PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()