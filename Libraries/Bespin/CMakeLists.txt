cmake_minimum_required(VERSION 3.9)
project(Bespin
        VERSION 0.0.1
        DESCRIPTION "Greetings from Bespin")

set(CMAKE_CXX_STANDARD 17)


include_directories(
	../../API/
)

add_library(Bespin SHARED
	../../API/IPlanet.h
	Bespin.h
	Bespin.cpp
)
