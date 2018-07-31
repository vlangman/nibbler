cmake_minimum_required (VERSION 3.11 FATAL_ERROR)
project(nibbler)
include(ExternalProject)
include(FetchContent)
add_executable(nibbler src/main.cpp src/Game.cpp src/Drawable.cpp src/Snake.cpp src/SnakeBody.cpp)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)



if(UNIX AND APPLE)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC -stdlib=libc++")
	message(STATUS "Compiling for unix osx system")
	#set the download directory where sfml will be installed
	set(SFML_INSTAL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML/build)
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
		${SFML_INSTALL_DIR}/sfmlLib.cpp
	)
	target_link_libraries(
		sfmlLib 
		sfml-graphics
		sfml-window
		sfml-system
	)
	target_link_libraries(nibbler sfmlLib)
	
elseif(UNIX AND NOT APPLE)
#LINUX
	set(CMAKE_CXX_FLAGS " -Wall -Wextra -std=c++11 -fPIC")
	message(STATUS "Compiling for linux")
	set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
	set(SFML_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML/build)
	set(SDL_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SDL/build)

	#download project sfml install Frameworks and dependancies
	FetchContent_Declare(
		sfml
		INSTALL_DIR ${SFML_INSTALL_DIR}
		SOURCE_DIR ${SFML_INSTALL_DIR}
		URL http://www.sfml-dev.org/files/SFML-2.5.0-linux-gcc-64-bit.tar.gz
	)
	FetchContent_Declare(
	  sdl
	  INSTALL_DIR ${SDL_INSTALL_DIR}
	  SOURCE_DIR ${SDL_INSTALL_DIR}
	  URL http://www.libsdl.org/release/SDL2-2.0.8.tar.gz
	  BINARY_DIR ${SDL_INSTALL_DIR}
	  BUILD_COMMAND $(MAKE)

	)

	FetchContent_GetProperties(sfml)
	if(NOT sfml_POPULATED)
	  FetchContent_Populate(sfml)
	  set(BUILD_SHARED_LIBS TRUE)
	endif()

	FetchContent_GetProperties(sdl)
	if(NOT sdl_POPULATED)
	  FetchContent_Populate(sdl)
	  set(BUILD_SHARED_LIBS TRUE)
	    add_subdirectory(${sdl_SOURCE_DIR} ${SDL_INSTALL_DIR})
	endif()

	

	include_directories(${sfml_SOURCE_DIR}/include)
	include_directories(${sdl_SOURCE_DIR}/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

	add_library(sfmlLib SHARED	${EXTERNAL_INSTALL_LOCATION}/SFML/sfmlLib.cpp)
	add_library(sdlLib SHARED ${EXTERNAL_INSTALL_LOCATION}/SDL/sdlLib.cpp)

	target_link_libraries(
		sfmlLib 
		sfml-graphics
		sfml-window
		sfml-system
	)
	#target_link_libraries(sdlLib ${EXTERNAL_INSTALL_LOCATION}/SDL/build/libSDL2-2.0.so)

	target_link_libraries(nibbler sfmlLib ${CMAKE_DL_LIBS})

endif()