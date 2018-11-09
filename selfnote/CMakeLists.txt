cmake_minimum_required (VERSION 3.4.1)
project (note)
set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_search_module(FFMPEG REQUIRED 
    libavcodec 
    libavformat 
    libavutil 
    libavdevice) #add here the list of ffmpeg components required

if(FFMPEG_FOUND)
#  FFMPEG_INCLUDE_DIRS  - Include directory necessary for using the required components headers.
#  FFMPEG_LIBRARIES     - Link these to use the required ffmpeg components.
#  FFMPEG_DEFINITIONS   - Compiler switches required for using the required ffmpeg components.
    message("FFMPEG_INCLUDE_DIRS = ${FFMPEG_INCLUDE_DIRS} ")
    message("FFMPEG_LIBRARIES = ${FFMPEG_LIBRARIES} ")
    message("FFMPEG_DEFINITIONS = ${FFMPEG_DEFINITIONS} ")
    include_directories(${FFMPEG_INCLUDE_DIRS})
endif()

pkg_search_module(SDL2 REQUIRED sdl2)
if(SDL2)
    message("SDL2_INCLUDE_DIRS = ${SDL2_INCLUDE_DIRS} ")
    message("SDL2_LIBRARIES = ${SDL2_LIBRARIES} ")
    message("SDL2_DEFINITIONS = ${SDL2_DEFINITIONS} ")
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

add_executable(avfilterDemo avfilterDemo.cpp)
target_link_libraries(avfilterDemo ${FFMPEG_LIBRARIES})

add_executable(sdldemo sdldemo.cpp)
target_link_libraries(sdldemo ${SDL2_LIBRARIES})
