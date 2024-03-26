#ifndef GLTOOLS_H
#define GLTOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct KeyManager KeyManager;
typedef struct GLToolsHandle GLToolsHandle;

typedef enum GLToolsInfo {
    GLToolsSuccess = 1,
    GLToolsFailure = 0,
} GLToolsInfo;

GLToolsInfo init_gltools(GLToolsHandle *handle);
int should_window_close(GLToolsHandle *handle);
void GLTools_SwapBuffers(GLToolsHandle *handle);
void destroy_handle(GLToolsHandle *handle);
char * get_error_message(GLToolsHandle *handle);
GLFWwindow *get_glfw_window(GLToolsHandle *handle);
KeyManager *get_key_manager(GLToolsHandle *handle);


#endif