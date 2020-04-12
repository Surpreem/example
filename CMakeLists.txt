cmake_minimum_required(VERSION 3.10)

project(example)

# Project basic path
set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIB_ROOT "${PROJECT_ROOT}/lib")
set(BIN_ROOT "${PROJECT_ROOT}/bin")


# C++ standard version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler options
message(STATUS "** Setting Compiler options")
if(MSVC)
    # https://docs.microsoft.com/ko-kr/cpp/porting/modifying-winver-and-win32-winnt
    add_definitions(-D_WIN32_WINNT=0x0601)
    add_definitions(-D_UNICODE)
    add_definitions(-DUNICODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
elseif(GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -Werror")
endif()


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIB_ROOT}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LIB_ROOT}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_ROOT}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(function_call)
add_subdirectory(fold_expression)
