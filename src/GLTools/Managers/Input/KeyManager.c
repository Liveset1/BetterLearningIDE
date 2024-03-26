#include "KeyManager.h"

#include "../../GLTools.h"

#define MAX_KEY_INPUTS 348

typedef struct Key Key;

typedef struct Key 
{
    int keyId;
    KeyState state;
} Key;

typedef struct KeyManager 
{
    Key keys[MAX_KEY_INPUTS];
    int isInitialized;
} KeyManager;

void glfw_key_callback(KeyManager *keyManager, int keyId, int keyState) {
    if (keyManager != NULL && !keyManager->isInitialized) {
        for (int i = 0; i < 348; i++) {
            keyManager->keys[i].keyId = i;
            keyManager->keys[i].state = Key_Released;
        }
        keyManager->isInitialized = 1;
    }
    keyManager->keys[keyId].state = keyState;
}

KeyState get_key_state(GLToolsHandle *handle, int keyId) {
    return glfwGetKey(get_glfw_window(handle), keyId);
}

KeyState is_key_pressed(GLToolsHandle *handle, int keyId) {
    return get_key_manager(handle)->keys[keyId].state;
}
KeyState is_key_released(GLToolsHandle *handle, int keyId) {
    return get_key_manager(handle)->keys[keyId].state;
}