#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>  // para size_t

/**
 * @brief Referência para strings C tradicionais.
 */
typedef char *str_ref;

/**
 * @brief Estrutura que representa uma string dinâmica.
 * 
 * Contém dados alocados dinamicamente, tamanho atual e capacidade.
 * Também possui um ponteiro para o método string_from.
 */
typedef struct String String;

struct String {
    str_ref data;                                 /**< Ponteiro para os dados da string */
    size_t length;                                /**< Número de caracteres na string */
    size_t capacity;                              /**< Capacidade total da string em bytes */
    
    /**
     * @brief Método que inicializa ou atualiza a string a partir de um str_ref.
     */
    void (*string_from)(String *self, const str_ref s);
};

/* ===========================================
 * Protótipos de funções
 * =========================================== */

/**
 * @brief Cria uma nova String com capacidade inicial especificada.
 * 
 * @param with_capacity Quantidade de caracteres desejada (sem contar null terminator).
 * @return String Inicializada.
 */
String new_string(size_t with_capacity);

/**
 * @brief Inicializa ou atualiza uma String a partir de um str_ref.
 * 
 * @param self Ponteiro para a String que será preenchida.
 * @param s Referência para a string de origem.
 */
void string_from(String *self, str_ref s);

/**
 * @brief Libera a memória alocada para uma String.
 * 
 * @param string Ponteiro para a String a ser liberada.
 */
void drop_string(String *string);

/**
 * @brief Libera a memória de uma str_ref se não for NULL.
 * 
 * @param ref Ponteiro para a referência de string a ser liberada.
 */
void drop_ref(str_ref *ref);

/**
 * @brief Adiciona a string à lista global de strings registradas.
 */
void register_string(String *s);

/**
 * @brief Remove a string da lista global de strings registradas.
 * 
 * @param string Ponteiro para a String a ser removida.
 * @param remove_string_too Se verdadeiro, também libera a memória da String.
 */
void unregister_string(String *string, bool remove_string_too);

/**
 * @brief Limpa todas as strings registradas.
 */
void clean_str();

/**
 * @brief Calcula o tamanho de uma string.
 * 
 * @param s Referência para a string.
 * @param return_terminator Se verdadeiro, inclui o null terminator no tamanho.
 * @return size_t Tamanho da string (com ou sem terminador).
 */
size_t str_length(str_ref s, bool return_terminator);

#endif // MY_STRING_H