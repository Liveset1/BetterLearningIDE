cmake_minimum_required(VERSION 3.29)

project(BetterLearningIDE C)
set(CMAKE_C_STANDARD 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} src/main.c src/glad.c)

target_include_directories(${PROJECT_NAME} PRIVATE include/ include/glfw/include/)
target_link_directories(${PROJECT_NAME} PRIVATE libs/)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32.lib libglfw3.a)