cmake_minimum_required(VERSION 3.0.0)
project(GeneratePermutation VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    src/Dictionary.cpp
    src/main.cpp
)

include_directories(./include)

add_executable(GeneratePermutation ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
