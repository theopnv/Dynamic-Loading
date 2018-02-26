cmake_minimum_required(VERSION 3.9)
project(Tatooine
        VERSION 0.0.1
        DESCRIPTION "Greetings from Tatooine")

set(CMAKE_CXX_STANDARD 17)


include_directories(
	../../API/
)

add_library(Tatooine SHARED
	../../API/IPlanet.h
	Tatooine.h
	Tatooine.cpp
)
