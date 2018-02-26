cmake_minimum_required(VERSION 3.9)
project(Greet-Core)

set(CMAKE_CXX_STANDARD 17)

### Output directory ###
set(CMAKE_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/Core/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})

## Sources ##
if (WIN32)
	set(DLLOADER_SRC
		Core/DLLoader/Windows/DLLoader.h
	)
	
	include_directories(
		Core/DLLoader/Windows/
	)

endif(WIN32)

if(UNIX)
	set(DLLOADER_SRC
		Core/DLLoader/Unix/DLLoader.h
	)

	include_directories(
		Core/DLLoader/Unix/
	)

    set (CMAKE_CXX_FLAGS "-W -Wall -Wextra")
endif(UNIX)

include_directories(
	Core/DLLoader/
	API/
)

add_executable(Greet-Core
	${DLLOADER_SRC}
	Core/main.cpp
)

target_link_libraries(Greet-Core ${CMAKE_DL_LIBS})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT Greet-Core)

add_subdirectory(Libraries/Tatooine)
add_subdirectory(Libraries/Bespin)