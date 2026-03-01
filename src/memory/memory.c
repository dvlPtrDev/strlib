#include "../../inc/display.h"
#include "../../inc/memory.h"

#include <stdlib.h>

bool isPointerNull(void *ptr, bool kill) {
    if (ptr == NULL) {
        if (kill) {
            fatal_print("Ponteiro nulo!", 0x1000);
        }
        return true;
    }
    return false;
}

void *allocate(void *buf, size_t alloc_bytes) {
    void *tmp = realloc(buf, alloc_bytes);
    isPointerNull(tmp, true);
    return tmp;
}
