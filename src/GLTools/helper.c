#include "helper.h"

#include <stdio.h>
#include <stdlib.h>

void *allocate(const char *nameOfObj, size_t sizeOfObj) {
    void *alloc = malloc(sizeOfObj);
    
    if (!alloc) {
        fprintf(stderr, "Failed to allocate memory for %s!\n", nameOfObj);
        return NULL; // Return NULL to indicate failure
    }
    
    return alloc;
}