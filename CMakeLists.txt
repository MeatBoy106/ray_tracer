cmake_minimum_required(VERSION 3.9)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 11)

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
