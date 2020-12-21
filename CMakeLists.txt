# include(GoogleTest)
cmake_minimum_required(VERSION 3.13)

message("________ SETUP MAKEFILE ________")
project(lena VERSION 1.0.0)
include_directories(   src/ 
                       inc/ 
                       lib/
                       /usr/include
)
# source_group(src/)

enable_testing()

set(CMAKE_CXX_FLAGS "-Wpedantic  -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 arch=native")
#add_compile_definitions(DEBUG)
set(CMAKE_CXX_STANDARD 17)
# add_executable( test_all src/parser.cpp test/test.cpp)
set(FILES "/src/*.cpp")
add_executable( lena 
                    src/main.cpp 
                    src/helpers.cpp
                    src/obraz.cpp
                    src/pgm_parser.cpp
                    src/ppm.cpp
                    src/pgm.cpp
                    src/ppm_parser.cpp
)

add_executable( test_lena 
                    test/test_main.cpp
                    test/test_obraz.cpp
                    test/test_pixel.cpp
                    src/helpers.cpp
                    src/obraz.cpp
                    src/pgm_parser.cpp
                    src/ppm.cpp
                    src/pgm.cpp
                    src/ppm_parser.cpp
)
add_executable( zadanie 
                    test/zadanie.cpp 
                    src/helpers.cpp
                    src/obraz.cpp
                    src/pgm_parser.cpp
                    src/ppm.cpp
                    src/ppm_parser.cpp
                    src/pgm.cpp
                    )

add_test(NAME test_lena COMMAND test_lena)
add_test(NAME zdanie COMMAND zadanie)
add_test(NAME lena COMMAND lena)