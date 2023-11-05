cmake_minimum_required(VERSION 3.10)

project(Librarie VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exec)

add_subdirectory(Librarie)
add_executable(LibrarieTest main.cpp)

target_link_libraries(LibrarieTest PUBLIC Magazin)
target_link_libraries(LibrarieTest PUBLIC Carte)
target_link_libraries(LibrarieTest PUBLIC Produs)
target_link_libraries(LibrarieTest PUBLIC Rechizita)
target_link_libraries(LibrarieTest PUBLIC BlackFriday)

target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie")