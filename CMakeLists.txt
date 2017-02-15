cmake_minimum_required(VERSION 3.2)
project(GraphicEngine C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# SRC & INCLUDE
#########################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
include_directories(./include
                    ./opengl/glew/include
                    ./opengl/glm/include
                    ./opengl/glfw/include
                    ./src/Snake)

set(SNAKE_SOURCE_FILES
        src/Snake/SnakeMain.cpp
        src/Snake/SnakeGame.cpp
        src/shader.cpp
        src/cube.cpp)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found! Install it to fix.")
endif(NOT OPENGL_FOUND)

#########################################################
# GLFW
#########################################################
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/opengl/glfw)

#########################################################
# GLEW
#########################################################
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/opengl/glew/lib")
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(ERROR " GLEW not found! Install it to fix.")
endif(NOT GLEW_FOUND)

#########################################################
# SOIL
#########################################################
set (LIB_SOIL libSOIL.a)
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/opengl/soil/lib")

#########################################################
# COMPILE
#########################################################
add_executable(DemoSnake3D ${SNAKE_SOURCE_FILES})

target_link_libraries(DemoSnake3D ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${LIB_SOIL} glfw)
