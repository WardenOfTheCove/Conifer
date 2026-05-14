cmake_minimum_required(VERSION 3.14)
project(engine)
find_package(glfw3 REQUIRED)
target_link_libraries(engine PRIVATE gladlib glfw)
