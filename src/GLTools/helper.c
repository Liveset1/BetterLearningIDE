#include "helper.h"

#include <stdio.h>

void *allocate(const char * nameOfObj, size_t sizeOfObj) {
    void *alloc = malloc(sizeOfObj);
    
    if (!alloc) {
        printf("Failed to allocate memory for %s!", nameOfObj);
        system("pause");
        exit(-1);
    }
    return alloc;
}