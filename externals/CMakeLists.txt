cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(external)

add_subdirectory(glfw EXCLUDE_FROM_ALL)
add_subdirectory(spdlog EXCLUDE_FROM_ALL)

add_library(glad STATIC glad/glad.c)

add_library(glad::glad ALIAS glad)
add_library(glfw::glfw ALIAS glfw)

target_include_directories(glad 
    PUBLIC
        glad/
    )

target_link_libraries(glad
    PUBLIC
        GL
        dl
    )
