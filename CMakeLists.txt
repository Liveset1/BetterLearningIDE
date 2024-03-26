cmake_minimum_required(VERSION 3.29)

project(BetterLearningIDE C)
set(CMAKE_C_STANDARD 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenGL REQUIRED)

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include/ include/glfw/include/ include/cglm/include src/)
target_link_directories(${PROJECT_NAME} PRIVATE libs/)
add_subdirectory(src/GLTools)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib libglfw3.a GLTools libcglm.dll.a)