cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(sword VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

find_package(SDL2 REQUIRED)

add_subdirectory(externals EXCLUDE_FROM_ALL)

add_executable(sword src/main.cpp)

target_link_libraries(sword 
    PUBLIC
        spdlog::spdlog
        glad::glad
        SDL2::Main
        glfw::glfw
        GL
        OpenGL
    )

target_include_directories(sword 
    PUBLIC
        src/
    )

add_subdirectory(src)
