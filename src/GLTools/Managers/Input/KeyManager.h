#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H

typedef struct GLToolsHandle GLToolsHandle;
typedef struct KeyManager KeyManager;

typedef enum KeyState 
{
    Key_Pressed = 1,
    Key_Released = 0,
} KeyState;

void glfw_key_callback(KeyManager *keyManager, int keyId, int keyState);
KeyState get_key_state(GLToolsHandle *handle, int keyId);
KeyState is_key_pressed(GLToolsHandle *handle, int keyId);
KeyState is_key_released(GLToolsHandle *handle, int keyId);

#endif