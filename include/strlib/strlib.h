#ifndef MY_STRING_H
#define MY_STRING_H


#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

/**
 * @brief Referência para strings imutáveis (const).
 */
 typedef const char *str;
 /*
 * @brief Referência para strings mutáveis.
 */
typedef char *mut_str;
/**
 * @brief Estrutura que representa uma string dinâmica.
 * 
 * Contém dados alocados dinamicamente, tamanho atual e capacidade.
 * Também possui um ponteiro para o método string_from.
 */

typedef struct String *String;

struct String {
    mut_str data; /**< Ponteiro para os dados da string */
    size_t length;                             /**< Número de caracteres na string */
    size_t capacity;                           /**< Capacidade total da string em bytes */
    
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
void string_from(String self, str s);

/**
 * @brief Libera a memória alocada para uma String.
 * 
 * @param string Ponteiro para a String a ser liberada.
 */
void drop_string(String string);

/**
 * @brief Limpa todas as strings registradas.
 * 
 * Percorre a lista global de strings, removendo e liberando todas.
 */
void clean_str();

/**
 * @brief Calcula o tamanho de uma string.
 * 
 * @param string Referência para a string.
 * @param return_terminator Se verdadeiro, inclui o null terminator no tamanho.
 * @return size_t Tamanho da string (com ou sem terminador).
 */
size_t str_len(str string, bool return_terminator);

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
bool compare_str(str s1, str s2);

/**
 * @brief Concatena uma str ao final de uma String dinâmica.
 * 
 * Ajusta a capacidade da String se necessário.
 * 
 * @param dest Ponteiro para a String de destino.
 * @param src str a ser concat_strenada.
 */
void concat_str(String dest, str src);

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
void copy_str(mut_str dest, str src, size_t bytes);
/**
 * @brief Cria uma string formatada similar a printf.
 *
 * Recebe uma string de formatação (`msg`) e argumentos variádicos, e retorna uma nova
 * string alocada dinamicamente contendo o resultado formatado. O buffer alocado
 * deve ser liberado pelo chamador usando `free` ou função equivalente de sua memória.
 *
 * @param msg String de formatação no estilo printf (ex.: "Idade: %d, Nome: %s").
 * @param ... Argumentos variádicos correspondentes à formatação da string.
 *
 * @return str Ponteiro para a string formatada alocada dinamicamente.
 *
 * @note Internamente, a função calcula o tamanho necessário usando `get_total_len` e
 *       chama `vsnprintf` para preencher o buffer.
 */
String vformat(str msg, va_list args);

/**
 * @brief Calcula o tamanho total necessário para formatar uma string com argumentos variádicos.
 *
 * Recebe uma lista de argumentos variádicos (`va_list`) e uma str de formatação (`s`), e retorna o número total de bytes necessários para armazenar
 * a string resultante, incluindo o caractere`\0`.
 *
 * @param args Lista de argumentos variádicos (tipo `va_list`) a serem usados na formatação.
 * A lista original não é consumida, mas é usada para criação da cópia
 * @param s A string de formatação no estilo printf (ex.: "Idade: %d, Nome: %s").
 *
 * @return n O número total de bytes necessários para armazenar a string formatada,
 *         incluindo o caractere nulo.
 */
int get_total_len(va_list args, str s);
/**
 * @brief Substitui todos os caracteres específicos em uma string.
 *
 * Percorre a string `s` e substitui cada ocorrência de `reject` pelo
 * caractere `replace_str`. A modificação é feita **in-place** na string
 * original.
 *
 * @param s A string mutável (`mut_str`) que será modificada.
 * @param reject O caractere que deve ser substituído.
 * @param replace_str O caractere que substituirá `reject`.
 *
 * @note A string `s` deve estar corretamente alocada e terminada em `\0`.
 * A função percorre até o terminador nulo e não retorna nada, alterando a string diretamente.
 *
 */
void replace_str(mut_str s, char reject, char replace_str);

/**
 * @brief Verifica se todos os caracteres de uma string são numéricos.
 * 
 * Percorre cada caractere da string fornecida e retorna `true` se todos
 * forem dígitos ('0' a '9'). Caso encontre qualquer caractere que não seja
 * um dígito, retorna `false`.
 * 
 * @param value Referência para a string a ser verificada.
 * 
 * @return true Se todos os caracteres forem numéricos.
 * @return false Se pelo menos um caractere não for um dígito.
 * 
 * @note A função utiliza `str_len(value, false)` para determinar
 *       o tamanho da string e percorre cada caractere sem depender do
 *       terminador nulo.
 */
bool is_numeric(str value);

/**
 * @brief Lê uma string a partir da stdin.
 *
 * Cria uma nova String e adiciona os caracteres lidos até encontrar
 * uma quebra de linha ou o fim da entrada.
 *
 * @return String Nova string contendo os caracteres recebidos.
 *
 * @note A memória retornada deve ser liberada pelo usuário quando não
 * for mais necessária.
 */
String read_line_str(void);

/**
 * @brief Adiciona um caractere ao final de uma String.
 *
 * Insere o caractere informado após o último caractere existente,
 * garantindo que a String possua capacidade suficiente e mantendo o
 * terminador nulo no final do buffer.
 *
 * @param self String que receberá o caractere.
 * @param c Caractere que será adicionado.
 */
void push_str(String self, char c);
void trim_str(mut_str s);

#endif