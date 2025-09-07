cmake_minimum_required(VERSION 3.10)
project(bhsim)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(bhsim src/main.cpp)
target_link_libraries(bhsim PRIVATE OpenGL::GL GLEW glfw glm)
