#ifndef MEMORY_H
#define MEMORY_H

#include "./strlib.h"
#include <stdbool.h>

bool isPointerNull(void *ptr, bool kill);
void *allocate(void *buf, size_t alloc_bytes);


#endif