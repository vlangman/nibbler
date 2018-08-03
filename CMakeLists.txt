cmake_minimum_required (VERSION 3.11 FATAL_ERROR)
project(nibbler)
include(ExternalProject)
include(FetchContent)
file(GLOB SOURCES src/*.cpp)
add_executable(nibbler ${SOURCES})
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
if(UNIX AND APPLE)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC -stdlib=libc++")
	message(STATUS "Compiling for unix osx system")
	

	#set the download directory where sfml will be installed
	set(SFML_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML/build)
	set(SDL_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SDL/build)
	set(NCURSES_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/NCURSES/build)
	
	#download project sfml install Frameworks and dependancies
	FetchContent_Declare(
		sfml
		INSTALL_DIR ${SFML_INSTALL_DIR}
		SOURCE_DIR ${SFML_INSTALL_DIR}
		URL https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip
	)

	FetchContent_Declare(
		sdl
		INSTALL_DIR ${SDL_INSTALL_DIR}
		SOURCE_DIR ${SDL_INSTALL_DIR}
		URL http://www.libsdl.org/release/SDL2-2.0.8.tar.gz
	)



	message(STATUS "fetching sfml")
	FetchContent_GetProperties(sfml)
	if(NOT sfml_POPULATED)
		FetchContent_Populate(sfml)
		set(BUILD_SHARED_LIBS TRUE)
		add_subdirectory(${sfml_SOURCE_DIR} ${SFML_INSTALL_DIR})
	endif()

	message(STATUS "fetching sdl")
	FetchContent_GetProperties(sdl)
	if(NOT sdl_POPULATED)
	  FetchContent_Populate(sdl)
	  set(BUILD_SHARED_LIBS TRUE)
	  add_subdirectory(${sdl_SOURCE_DIR} ${SDL_INSTALL_DIR})
	endif()



	
	include_directories(${sfml_SOURCE_DIR}/include)
	include_directories(${sdl_SOURCE_DIR}/include)


	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

	#linking to my libraries before linking them to the graphics libs
	add_library(sfmlLib SHARED ${EXTERNAL_INSTALL_LOCATION}/SFML/sfmlLib.cpp)
	add_library(sdlLib SHARED ${EXTERNAL_INSTALL_LOCATION}/SDL/sdlLib.cpp)
	add_library(ncursesLib SHARED ${EXTERNAL_INSTALL_LOCATION}/NCURSES/ncursesLib.cpp)


	find_package(Curses REQUIRED)

	#build sdl dynamic libraries
	add_custom_target(
		sdlBuild 
		COMMAND make
		WORKING_DIRECTORY ${SDL_INSTALL_DIR}
	)
	add_dependencies(sdlLib sdlBuild)

	#link my libraries to dylibs
	target_link_libraries(ncursesLib ${CURSES_LIBRARIES})
	target_link_libraries(sdlLib ${EXTERNAL_INSTALL_LOCATION}/SDL/build/libSDL2.dylib)
	target_link_libraries(sfmlLib sfml-graphics sfml-window sfml-system)
	target_link_libraries(nibbler sfmlLib sdlLib ncursesLib)
	
elseif(UNIX AND NOT APPLE)
#LINUX
	set(CMAKE_CXX_FLAGS " -Wall -Wextra -fPIC -std=c++11")
	message(STATUS "Compiling for linux")
	set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
	set(SFML_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SFML/build)
	set(SDL_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/SDL/build)
	set(NCURSES_INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}/NCURSES/build)
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
	FetchContent_Declare(
	  ncurses
	  INSTALL_DIR ${NCURSES_INSTALL_DIR}
	  SOURCE_DIR ${NCURSES_INSTALL_DIR}
	  URL http://invisible-island.net/datafiles/release/ncurses.tar.gz
	  BINARY_DIR ${NCURSES_INSTALL_DIR}
	  BUILD_COMMAND $(MAKE)
	)
	message(STATUS "fetching sfml")
	FetchContent_GetProperties(sfml)
	if(NOT sfml_POPULATED)
	  FetchContent_Populate(sfml)
	  set(BUILD_SHARED_LIBS TRUE)
	endif()
	
	message(STATUS "fetching sdl")
	FetchContent_GetProperties(sdl)
	if(NOT sdl_POPULATED)
	  FetchContent_Populate(sdl)
	  set(BUILD_SHARED_LIBS TRUE)
	  add_subdirectory(${sdl_SOURCE_DIR} ${SDL_INSTALL_DIR})
	endif()
	
	message(STATUS "fetching ncurses")
	FetchContent_GetProperties(ncurses)
	if(NOT ncurses_POPULATED)
	  FetchContent_Populate(ncurses)
	  set(BUILD_SHARED_LIBS TRUE)
	endif()
	
	include_directories(${sfml_SOURCE_DIR}/include)
	include_directories(${sdl_SOURCE_DIR}/include)
	include_directories(${ncurses_SOURCE_DIR}/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


	add_library(sfmlLib SHARED  ${EXTERNAL_INSTALL_LOCATION}/SFML/sfmlLib.cpp)
	add_library(sdlLib SHARED ${EXTERNAL_INSTALL_LOCATION}/SDL/sdlLib.cpp)
	add_library(ncursesLib SHARED ${EXTERNAL_INSTALL_LOCATION}/NCURSES/ncursesLib.cpp)


	find_package(Curses REQUIRED)
	add_custom_target(
		sdlBuild 
		COMMAND make
		WORKING_DIRECTORY ${SDL_INSTALL_DIR}
	)
	add_dependencies(sdlLib sdlBuild)
	
	target_link_libraries(ncursesLib ${CURSES_LIBRARIES})
	target_link_libraries(sdlLib ${EXTERNAL_INSTALL_LOCATION}/SDL/build/libSDL2-2.0.so)
	target_link_libraries(sfmlLib sfml-graphics sfml-window sfml-system)
	target_link_libraries(nibbler sfmlLib sdlLib ncursesLib ${CMAKE_DL_LIBS})
endif()