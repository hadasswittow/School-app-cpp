cmake_minimum_required(VERSION 3.14)
project(schoolexe)

set(CMAKE_CXX_STANDARD 98)

add_executable(schoolexe main.cpp Person.cpp Person.h Student.cpp Student.h Teacher.cpp Teacher.h School.cpp School.h Tests.cpp Tests.h MyString.h MyString.cpp stringFunctions.h stringFunctions.cpp)