#include "../../inc/display.h"
#include "../../inc/memory.h"

void isPointerNull(void *ptr) {
    if (ptr == NULL) {
        fatal_err("This pointer is null!", 0x1000);
    }
}

void *allocate(void *buf, size_t alloc_bytes) {
    void *ptr = realloc(buf, alloc_bytes);
    isPointerNull(ptr);
    return ptr;
}

void dropString(String *string) {
    free(string->data);
    string->data = NULL;
    string->string_from = NULL;    
    string->capacity = 0;
    string->length = 0;
}