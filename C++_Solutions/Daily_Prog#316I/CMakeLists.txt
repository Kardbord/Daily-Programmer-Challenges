cmake_minimum_required(VERSION 3.7)
project(Daily_Prog_316I)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Cart.cpp Cart.h Promotion.cpp Promotion.h ToursDB.cpp ToursDB.h Tour.cpp Tour.h PromoDB.cpp PromoDB.h Utils.cpp Utils.h)
add_executable(Daily_Prog_316I ${SOURCE_FILES})