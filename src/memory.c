#include "../internal/display.h"

#include <memory.h>
#include <stdlib.h>

void *allocate(void *buf, size_t alloc_bytes)
{
    void *tmp = realloc(buf, alloc_bytes);
    if(!tmp) fatal_print("Error reallocating pointer!", 0x1000);
    return tmp;
}
void deallocate(void **ptr) 
{    
    if (ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}