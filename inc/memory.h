#ifndef MEMORY_H
#define MEMORY_H

#include "./strlib.h"
#include <stdbool.h>
#include <stddef.h>  // Para size_t

/* ===========================================
 * Funções de alocação e verificação de ponteiros
 * =========================================== */

/**
 * @brief Verifica se um ponteiro é NULL.
 * 
 * @param ptr Ponteiro a ser verificado.
 * @param kill Se verdadeiro, encerra o programa com fatal_print.
 * @return true Se o ponteiro for NULL.
 * @return false Caso contrário.
 */
bool isPointerNull(void *ptr, bool kill);

/**
 * @brief Aloca ou realoca memória para um buffer.
 * 
 * @param buf Ponteiro existente ou NULL.
 * @param alloc_bytes Tamanho em bytes a ser alocado.
 * @return void* Ponteiro para a memória alocada.
 */
void *allocate(void *buf, size_t alloc_bytes);

#endif // MEMORY_H