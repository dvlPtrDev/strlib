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
    size_t length;                             /**< Número de caracteres na string */
    size_t capacity;                           /**< Capacidade total da string em bytes */
    
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
 * 
 * Útil para gerenciamento centralizado de memória e limpeza.
 * 
 * @param s Ponteiro para a String a ser registrada.
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
 * 
 * Percorre a lista global de strings, removendo e liberando todas.
 */
void clean_str();

/**
 * @brief Recalcula a capacidade de uma string para garantir espaço suficiente.
 * 
 * @param capacity Capacidade atual.
 * @param min_capacity Capacidade mínima necessária.
 * @return size_t Nova capacidade ajustada.
 */
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

/**
 * @brief Concatena uma str ao final de uma String dinâmica.
 * 
 * Ajusta a capacidade da String se necessário.
 * 
 * @param dest Ponteiro para a String de destino.
 * @param src str a ser concatenada.
 */
void string_concat(String *dest, str src);

/**
 * @brief Copia um número de bytes str para outra.
 * 
 * Pode desempenhar o papel de strcpy() se bytes for NULL
 * Ou de memcpy() se um valor válido for passado para bytes
 * 
 * @param dest Destino da cópia.
 * @param src Origem da cópia.
 * @param bytes Quantidade de bytes a copiar. NULL para copiar a string até \0.
 */
void string_copy(str dest, str src, size_t bytes);

#endif // MY_STRING_H