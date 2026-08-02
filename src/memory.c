#include "internal/display.h"
#include "internal/memory.h"

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


size_t recalc_capacity(size_t capacity, size_t min_capacity)
{
    size_t new_capacity = capacity != 0 ? capacity : 1; 
    // Garante que não aconteça 0 * 2
    for (; new_capacity < min_capacity; new_capacity<<=1); 
    // dobra new_capacity com bitwise, mais rápida que new_capacity*=2 com bytes maiores 
    return new_capacity;
}
void ensure_string_capacity(String self, size_t min_capacity)
{
    if (self->capacity >= min_capacity)
        return;

    size_t new_capacity = recalc_capacity(self->capacity, min_capacity);

    self->data = allocate(self->data, new_capacity);
    self->capacity = new_capacity;
}