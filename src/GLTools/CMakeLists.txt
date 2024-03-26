cmake_minimum_required(VERSION 3.29)

project(GLTools C)
set(CMAKE_C_STANDARD 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB SOURCES "*.c")
file(GLOB HEADERS "*.h")
file(GLOB MANAGERS_SOURCES "Managers/*.c")
file(GLOB MANAGERS_HEADERS "Managers/*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS} ${MANAGERS_SOURCES} ${MANAGERS_HEADERS} ../glad.c)

target_include_directories(${PROJECT_NAME} PRIVATE ../../include/ ../../include/glfw/include/ ../../include/cglm/include)
target_link_directories(${PROJECT_NAME} PRIVATE libs/)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib libglfw3.a libcglm.dll.a)