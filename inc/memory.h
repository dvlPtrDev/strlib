#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

void isPointerNull(void *ptr);
void *allocate(void *buf, size_t alloc_bytes);

#endif