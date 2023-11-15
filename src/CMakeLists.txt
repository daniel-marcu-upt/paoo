cmake_minimum_required(VERSION 3.10)

project(Librarie VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-W3)


add_subdirectory(Librarie)
add_subdirectory(Librarie/Carte)
add_subdirectory(Librarie/Produs)
add_subdirectory(Librarie/Rechizita)
add_subdirectory(Librarie/BlackFriday)

add_executable(LibrarieTest main.cpp)

target_link_libraries(LibrarieTest PUBLIC Magazin)
target_link_libraries(LibrarieTest PUBLIC Carte)
target_link_libraries(LibrarieTest PUBLIC Produs)
target_link_libraries(LibrarieTest PUBLIC Rechizita)
target_link_libraries(LibrarieTest PUBLIC BlackFriday)

target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie/Carte")
target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie/Produs")
target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie/Rechizita")
target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie/BlackFriday")
target_include_directories(LibrarieTest PUBLIC "${PROJECT_SOURCE_DIR}/Librarie")