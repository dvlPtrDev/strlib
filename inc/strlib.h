#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Referência para strings C tradicionais.
 */
typedef char *str;

/**
 * @brief Estrutura que representa uma string dinâmica.
 * 
 * Contém dados alocados dinamicamente, tamanho atual e capacidade.
 * Também possui um ponteiro para o método string_from.
 */
typedef struct String String;

struct String {
    str data;                                 /**< Ponteiro para os dados da string */
    size_t length;                                /**< Número de caracteres na string */
    size_t capacity;                              /**< Capacidade total da string em bytes */
    
    /**
     * @brief Método que inicializa ou atualiza a string a partir de um str.
     */
    void (*string_from)(String *self, const str s);
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
 * @brief Inicializa ou atualiza uma String a partir de um str.
 * 
 * @param self Ponteiro para a String que será preenchida.
 * @param s Referência para a string de origem.
 */
String str_into_string(str ref, size_t capacity);

void string_from(String *self, str s);

/**
 * @brief Libera a memória alocada para uma String.
 * 
 * @param string Ponteiro para a String a ser liberada.
 */
void drop_string(String *string);

/**
 * @brief Libera a memória de uma str se não for NULL.
 * 
 * @param ref Ponteiro para a referência de string a ser liberada.
 */
void drop_ref(str *ref);
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

size_t recalc_capacity(size_t capacity, size_t min_capacity);

/**
 * @brief Calcula o tamanho de uma string.
 * 
 * @param string Referência para a string.
 * @param return_terminator Se verdadeiro, inclui o null terminator no tamanho.
 * @return size_t Tamanho da string (com ou sem terminador).
 */
size_t string_length(str string, bool return_terminator);
/**
 * @brief Compara duas strings para verificar se são iguais.
 * 
 * Percorre cada caractere das duas strings e retorna false
 * se encontrar qualquer diferença. Retorna true apenas se
 * ambas tiverem o mesmo tamanho e conteúdo.
 * 
 * @param s1 Primeira string a ser comparada.
 * @param s2 Segunda string a ser comparada.
 * @return true Se as strings forem iguais.
 * @return false Caso contrário.
 */
bool string_compare(str s1, str s2);
void string_concat(String *dest, str src);
void string_copy(str *dest, str src);

#endif // MY_STRING_H