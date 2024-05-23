cmake_minimum_required(VERSION 3.28)
project(cprod)

set(CMAKE_CXX_STANDARD 14)

add_executable(cprod main.cpp
        structs/student.h
        structs/topic.h
        structs/question.h
        initialization/parsing/student_file_parse/student_parse.cpp
        initialization/parsing_header.h
        initialization/read_student_file.cpp
        initialization/initialization_header.h
        increase_array.h
        utils/utils.h
        utils/array/increase_array.cpp
)
