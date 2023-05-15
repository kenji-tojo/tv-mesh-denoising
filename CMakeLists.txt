cmake_minimum_required(VERSION 3.20)
project(denoiser LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(denoiser main.cpp)
target_include_directories(denoiser PRIVATE ext)
target_link_libraries(denoiser PRIVATE Eigen3::Eigen)