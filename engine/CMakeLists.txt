cmake_minimum_required(VERSION 3.20)

project(gvsx-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.hpp src/*.c src/*.cpp)

include_directories(
        src
		thridparty/glfw/include/GLFW
		thridparty/glm/glm
		)
		
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glm)

target_link_libraries(${PROJECT_NAME} PRIVATE d3d11)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw glm)