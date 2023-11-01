cmake_minimum_required(VERSION 3.10)

project(Librarie VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Librarie)
add_executable(LibrarieTest main.cpp)

target_link_libraries(LibrarieTest PUBLIC Librarie)
target_link_libraries(LibrarieTest PUBLIC Carte)
target_link_libraries(LibrarieTest PUBLIC Produs)
target_link_libraries(LibrarieTest PUBLIC Rechizita)

target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie")