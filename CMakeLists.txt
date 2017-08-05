cmake_minimum_required(VERSION 3.7)
project(quoids)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/environment.cpp src/environment.h src/tile.h src/chemistry.cpp src/chemistry.h src/thing.cpp src/thing.h src/living_thing.cpp src/living_thing.h src/mammal.cpp src/mammal.h src/plant.cpp src/plant.h src/seed.cpp src/seed.h src/Fruit.cpp src/Fruit.h src/game.cpp src/game.h src/genetic.h src/genetic.cpp)
add_executable(quoids ${SOURCE_FILES})