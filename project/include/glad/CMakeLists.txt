cmake_minimum_required(VERSION 3.14)
project(gladlib)
add_library(gladlib glad.c)

set_target_properties(gladlib PROPERTIES PUBLIC_HEADER glad.h)

install(TARGETS gladlib LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include/gladlib
        )
