cmake_minimum_required(VERSION 3.20)
project(denoiser LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(LIBIGL_WITH_OPENGL OFF)
set(LIBIGL_WITH_OPENGL_GLFW OFF)
set(LIBIGL_WITH_VIEWER OFF)
set(LIBIGL_WITH_OPENGL_GLFW_IMGUI OFF)
set(LIBIGL_DIR ${CMAKE_CURRENT_LIST_DIR}/ext/libigl)
add_subdirectory(${LIBIGL_DIR})

add_executable(denoiser main.cpp)
target_include_directories(denoiser PRIVATE ext ${LIBIGL_DIR}/include)
target_link_libraries(denoiser PRIVATE Eigen3::Eigen)