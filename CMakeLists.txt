cmake_minimum_required(VERSION 3.10)
project(c_opengl_course)

set(CMAKE_CXX_STANDARD 17)

# GLFW
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

# GLAD
add_library(glad libs/glad/src/gl.c)
target_include_directories(glad PUBLIC libs/glad/include)

# GLM
include_directories(libs/glm)

# Source files
file(GLOB SRC_FILES src/*.cpp)

add_executable(c_opengl_course ${SRC_FILES})
target_link_libraries(c_opengl_course glfw glad)