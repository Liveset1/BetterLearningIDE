#include "GLTools.h"

#include "helper.h"
#include "Managers/Input/KeyManager.h"

typedef struct GLToolsHandle
{
    GLFWwindow *window;
    GLToolsInfo info;
    char *err_msg;
    KeyManager *keyManager;
} GLToolsHandle;

// ============================================================================

// -------------------------------
// MISC HELPER FUNCTIONS
// -------------------------------

// Handles Failures and returns it
GLToolsInfo failure(GLToolsHandle *handle, char *err_msg) {
    if (err_msg) {
        handle->info = GLToolsFailure;
        handle->err_msg = err_msg;
    }
    return GLToolsFailure;
}

// Handles Successess and returns it
GLToolsInfo success(GLToolsHandle *handle) {
    handle->info = GLToolsSuccess;
    handle->err_msg = "";
    return GLToolsSuccess;
}

// ============================================================================

// -------------------------------
// INIT FUNCTIONS
// -------------------------------

// Creates GLFW Window and Such
GLToolsInfo init_glfw(GLToolsHandle *handle) {
    /* Initialize the library */
    if (!glfwInit())
        return failure(handle, "GLFW failed to initialized!");

     /* Create a windowed mode window and its OpenGL context */
    handle->window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!handle->window)
    {   
        glfwTerminate();
        return failure(handle, "GLFW window was not created properly!");
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(handle->window);
    gladLoadGL();

    // Set Window User Pointer
    glfwSetWindowUserPointer(handle->window, handle);
    
    return success(handle);
}

GLToolsInfo initGLTools(GLToolsHandle *handle) {
    handle->keyManager = (KeyManager *) allocate("KeyManager", sizeof(KeyManager*));
}

// ============================================================================

// -------------------------------
// GLFW CALLBACK FUNCTIONS
// -------------------------------

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    GLToolsHandle *handle = (GLToolsHandle*) glfwGetWindowUserPointer(window);
    
    if (handle) {
        KeyManager *keyManager = handle->keyManager;

        if (keyManager) {
            glfw_key_callback(keyManager, key, action);
        }
    }
}

// ============================================================================

// -------------------------------
// SETUP GLFW CALLBACK FUNCTION
// -------------------------------

void setup_glfw_callbacks(GLToolsHandle *handle) {
    // TODO: CONTINUE HERE
    // TODO: ADD GLFW CALLBACKS FOR ON_WINDOW_RESIZE and ON_KEY_PRESSED
    // TODO: MAKE IT A KEY MANAGER TO HANDLE KEY INPUTS

    glfwSetKeyCallback(handle->window, key_callback);
}

// ============================================================================

// -------------------------------
// PUBLIC FUNCTIONS
// -------------------------------

GLToolsInfo init_gltools(GLToolsHandle *handle) {
    // Initialize GLFW
    GLToolsInfo initGLFWInfo = init_glfw(handle);
    if (!initGLFWInfo) {
        return initGLFWInfo;
    }

    initGLTools(handle);

    setup_glfw_callbacks(handle);
    return GLToolsSuccess;
}

int should_window_close(GLToolsHandle *handle) {
    if (handle) {
        return glfwWindowShouldClose(handle->window);
    }
    return 0;
}

void GLTools_SwapBuffers(GLToolsHandle *handle) {
    if (handle) {
        glfwSwapBuffers(handle->window);
    }
}

void destroy_handle(GLToolsHandle *handle) {
    if (handle) {
        free(handle->keyManager);
        free(handle);
    }
}

char * get_error_message(GLToolsHandle *handle) {
    if (handle) {
        return handle->err_msg;
    }
    return "Handle is missing; Could not retrieve error message!";
}

GLFWwindow *get_glfw_window(GLToolsHandle *handle) {
    if (handle) {
        return handle->window;
    }
    return NULL;
}

KeyManager *get_key_manager(GLToolsHandle *handle) {
    if (handle) {
        return handle->keyManager;
    }
    return NULL;
}

// ============================================================================