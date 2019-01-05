cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")



project(yourname)



find_package(SDL2 REQUIRED)
include_directories(${SDLIMAGE_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})


add_executable(
yourname
Print.h
main.cpp
Print.cpp

)
target_link_libraries(yourname ${SDL2_LIBRARIES} SDL2_IMAGE SDL2_TTF)
                            