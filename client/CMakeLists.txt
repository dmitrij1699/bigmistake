cmake_minimum_required (VERSION 3.8)



project (bigmistake)

#/set(SOURCE "source/main.cpp" "source/buff.cpp" "source/Ltext.cpp")

set(SOURCE "source/main.cpp" 
    "source/buff.cpp" 
    "source/Ltext.cpp" 
    "source/engine.cpp" 
    "source/objects.cpp" )

add_executable(bigmistake ${SOURCE})

#set(CMAKE_BUILD_TYPE Debug)

add_definitions(-std=c++11 -Wall -DGLEW_STATIC)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("source/libs/glfw-3.2.1")

 target_link_libraries(bigmistake glfw)

  find_package(OpenGL REQUIRED)

 target_link_libraries(bigmistake ${OPENGL_gl_LIBRARY})

 find_package(GLEW REQUIRED)
if(GLEW_FOUND)
    message(${GLEW_INCLUDE_DIRS})
endif()
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})

find_library(SOIL REQUIRED)

target_link_libraries(bigmistake ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        SOIL)

#/home/dmitrij/glfw3/glfw
