# include(GoogleTest)
cmake_minimum_required(VERSION 3.13)

message("________ SETUP MAKEFILE ________")
project(lena VERSION 1.0.0)
include_directories(   src/ 
                       inc/ 
                       /usr/include
)
# source_group(src/)

enable_testing()

set(CMAKE_CXX_FLAGS "-Wpedantic -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 arch=native")
#add_compile_definitions(DEBUG)
set(CMAKE_CXX_STANDARD 17)
# add_executable( test_all src/parser.cpp test/test.cpp)
set(FILES "/src/*.cpp")
add_executable( lena 
                    src/main.cpp 
                    src/parser.cpp 
                    src/ppm.cpp
                    src/obraz.cpp
                    src/parser_ppm.cpp
)

add_executable( test_lena 
                    test/test_main.cpp 
                    test/test_pixel.cpp 
                    test/test_obraz.cpp
                    src/parser.cpp 
                    src/ppm.cpp
                    src/obraz.cpp
)
add_executable( zadanie 
                    test/zadanie.cpp
                    src/parser.cpp 
                    src/ppm.cpp
                    src/obraz.cpp
                    )

add_test(NAME test_lena COMMAND test_lena)
add_test(NAME zdanie COMMAND zadanie)
add_test(NAME lena COMMAND lena)