cmake_minimum_required (VERSION 3.11 FATAL_ERROR)
project(nibbler)
include(ExternalProject)
include(FetchContent)
add_executable(nibbler src/main.cpp src/Game.cpp)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
if(UNIX AND APPLE)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC -stdlib=libc++")
	message(STATUS "Compiling for unix osx system")
	#set the download directory where sfml will be installed
	set(SFML_INSTAL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML)
	#download project sfml install Frameworks and dependancies
	FetchContent_Declare(
	  sfml
	  URL https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip
	)
	FetchContent_GetProperties(sfml)
	if(NOT sfml_POPULATED)
	  FetchContent_Populate(sfml)
	  set(BUILD_SHARED_LIBS TRUE)
	  add_subdirectory(${sfml_SOURCE_DIR} ${SFML_INSTAL_DIR})
	endif()
	
	include_directories(${sfml_SOURCE_DIR}/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
	add_library(sfmlLib SHARED
		${SFML_INSTAL_DIR}/sfmlLib.cpp
	)
	target_link_libraries(
		sfmlLib 
		sfml-graphics
		sfml-window
		sfml-system
	)
	target_link_libraries(nibbler sfmlLib)
	
else ()
#LINUX
	set(CMAKE_CXX_FLAGS " -Wall -Wextra -std=c++11 -ldl")
	set(CMAKE_EXE_LINKER_FLAGS "-ldl")
	message(STATUS "Compiling for linux")
	set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
	set(SFML_INSTAL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML)


	#download project sfml install Frameworks and dependancies
	FetchContent_Declare(
	  sfml
	  URL http://www.sfml-dev.org/files/SFML-2.5.0-linux-gcc-64-bit.tar.gz
	)

	FetchContent_GetProperties(sfml)
	if(NOT sfml_POPULATED)
	  FetchContent_Populate(sfml)
	  set(BUILD_SHARED_LIBS TRUE)
	endif()

	include_directories(${sfml_SOURCE_DIR}/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

	add_library(sfmlLib SHARED
		${SFML_INSTAL_DIR}/sfmlLib.cpp
	)
	target_link_libraries(
		sfmlLib 
		sfml-graphics
		sfml-window
		sfml-system
	)
	target_link_libraries(nibbler sfmlLib)
endif()