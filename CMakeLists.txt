cmake_minimum_required(VERSION 3.9)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

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