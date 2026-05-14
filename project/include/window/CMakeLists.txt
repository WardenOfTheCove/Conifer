cmake_minimum_required(VERSION 3.14)
project(winlib)
add_library(winlib window.cpp)

set_target_properties(winlib PROPERTIES PUBLIC_HEADER window.hpp)

install(TARGETS winlib LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include/winlib)
