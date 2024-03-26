#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <GLTools/helper.h>
#include <GLTools/GLTools.h>
#include <GLTools/Managers/Input/KeyManager.h>

int main(void)
{
    GLToolsHandle *handle = (GLToolsHandle*) allocate("Main Handle", sizeof(GLToolsHandle*));
    
    init_gltools(handle);
    printf("%s\n", get_error_message(handle));

    /* Loop until the user closes the window */
    while (!should_window_close(handle))
    {
        /* Render here */
        glClearColor(0.5, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();

        if (is_key_pressed(handle, GLFW_KEY_B) == Key_Pressed) {
            glRotatef(1.0f, 0.0f, 0.0f, 1.0f);
        }

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
        glEnd();

        glPopMatrix();
        /* Swap front and back buffers */
        GLTools_SwapBuffers(handle);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Free Handle and Terminate GLFW
    glfwTerminate();
    destroy_handle(handle);

    getchar();

    return 0;
}