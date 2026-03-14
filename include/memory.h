#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>
#include <stddef.h>  

/**
 * @brief Aloca ou realoca memória para um buffer.
 * 
 * @param buf Ponteiro existente ou NULL.
 * @param alloc_bytes Tamanho em bytes a ser alocado.
 * @return void* Ponteiro para a memória alocada.
 */
void *allocate(void *buf, size_t alloc_bytes);
void deallocate(void **ptr);

#endif // MEMORY_H