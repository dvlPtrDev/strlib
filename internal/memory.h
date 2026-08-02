#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Aloca ou realoca memória para um buffer existente.
 *
 * Caso `buf` seja NULL, realiza uma nova alocação. Caso contrário,
 * redimensiona o bloco de memória existente.
 *
 * @param buf Ponteiro para o bloco de memória existente ou NULL.
 * @param alloc_bytes Quantidade de bytes desejada para a alocação.
 * @return void* Ponteiro para o bloco de memória alocado.
 *
 * @note Encerra a execução caso a alocação falhe.
 */
void *allocate(void *buf, size_t alloc_bytes);

/**
 * @brief Libera memória alocada e redefine o ponteiro para NULL.
 *
 * Recebe um ponteiro para um ponteiro, permitindo liberar a memória
 * e evitar que o ponteiro original permaneça apontando para uma região
 * inválida.
 *
 * @param ptr Endereço do ponteiro que será liberado.
 *
 * @note Não faz nada caso `ptr` ou `*ptr` sejam NULL.
 */
void deallocate(void **ptr);

/**
 * @brief Calcula uma nova capacidade para um buffer.
 *
 * Aumenta a capacidade atual dobrando seu tamanho até que ela seja
 * suficiente para armazenar a capacidade mínima necessária.
 *
 * @param capacity Capacidade atual do buffer.
 * @param min_capacity Capacidade mínima requerida.
 * @return size_t Nova capacidade calculada.
 *
 * @note A capacidade cresce em potências de 2 para reduzir realocações
 * frequentes.
 */
size_t recalc_capacity(size_t capacity, size_t min_capacity);

/**
 * @brief Garante que a String possua capacidade suficiente.
 *
 * Verifica a capacidade atual da String e, caso seja menor que a capacidade
 * mínima necessária, aumenta o buffer interno.
 *
 * @param self String que terá sua capacidade ajustada.
 * @param min_capacity Capacidade mínima necessária em bytes.
 *
 * @note Não reduz a capacidade existente caso ela já seja suficiente.
 * @note Realoca a memória interna quando necessário.
 */
void ensure_string_capacity(String self, size_t min_capacity);
#endif // MEMORY_H