cmake_minimum_required(VERSION 3.14)

project(MySudokuCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check for MSVC
if (MSVC)
    if (NOT (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.20 AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 20.0))
        message(FATAL_ERROR "MSVC 2019 is required!")
    endif()

    add_compile_options("/source-charset:utf-8")
    add_compile_options("/execution-charset:utf-8")
# Check for GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (NOT (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13.0))
        message(FATAL_ERROR "GCC 13 is required!")
    endif()

    add_compile_options("-finput-charset=utf-8")
    add_compile_options("-fexec-charset=utf-8")
else()
    message(FATAL_ERROR "Unsupported compiler!")
endif()

add_executable(MySudokuCpp
  main.cpp
  SudokuValue.h SudokuValue.cpp
  SudokuBlock.h SudokuBlock.cpp
  gameconfig.h gameconfig.cpp
  colormodifier.h colormodifier.cpp
  gamescene.h gamescene.cpp
  gamecontroller.h gamecontroller.cpp
  gamecommand.h gamecommand.cpp
)
