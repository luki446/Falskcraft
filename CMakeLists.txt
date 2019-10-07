cmake_minimum_required(VERSION 3.10)
project(Falskcraft)

find_package(OpenGL REQUIRED)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Select other build directory for example build/" )
endif()

if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS_DEBUG "/DEBUG /D__DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -D__DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )


message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(ext/glfw)

include_directories(ext/glfw/include/
                    ext/glad/include/
                    ext/glm/)

file(GLOB GLAD_FILE ext/glad/src/glad.c)
file(GLOB PROJECT_FILES src/*.cpp
    src/*/*.cpp)

add_definitions(-DGLFW_INCLUDE_NONE)

file(GLOB GAME_RESOURCES
    res/*.jpg
    res/*.png
    res/*.jpeg)
file(COPY ${GAME_RESOURCES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

option(Random_BuildTests OFF)
add_subdirectory(ext/random)

add_executable(${PROJECT_NAME} ${PROJECT_FILES} ${GLAD_FILE})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} glfw ${GLFW_LIBRARIES} effolkronium_random)
