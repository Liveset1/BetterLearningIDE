cmake_minimum_required(VERSION 3.29)

project(GLTools C)
set(CMAKE_C_STANDARD 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE HEADERS "*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS} ${MANAGERS_SOURCES} ${MANAGERS_HEADERS} ../glad.c)

target_include_directories(${PROJECT_NAME} PRIVATE ../../include/ ../../include/glfw/include/ ../../include/cglm/include)
target_link_directories(${PROJECT_NAME} PRIVATE libs/)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib libglfw3.a libcglm.dll.a)

message("List of GLTools files (SOURCES):")
foreach(FILE ${SOURCES})
    message("\t${FILE}")
endforeach()

message("List of GLTools files (HEADERS):")
foreach(FILE ${HEADERS})
    message("\t${FILE}")
endforeach()