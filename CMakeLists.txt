cmake_minimum_required (VERSION 3.8)



project (bigmistake)

set(SOURCE "source/main.cpp" )

add_executable(bigmistake ${SOURCE})

add_definitions(-std=c++11 -Wall -DGLEW_STATIC)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("/home/dmitrij/bigmistake/source/libs/glfw-3.2.1")

 target_link_libraries(bigmistake glfw)

  find_package(OpenGL REQUIRED)

 target_link_libraries(bigmistake ${OPENGL_gl_LIBRARY})

 find_package(GLEW REQUIRED)
if(GLEW_FOUND)
    message( "glew was found")
endif()
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})

find_library(SOIL REQUIRED)

target_link_libraries(bigmistake ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        SOIL)

#/home/dmitrij/glfw3/glfw