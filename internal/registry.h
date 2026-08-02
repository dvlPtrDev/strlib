#ifndef REGISTRY_H
#define REGISTRY_H

typedef struct String *String;
/**
 * @brief Adiciona a string à lista global de strings registradas.
 * 
 * @param s Ponteiro para a String a ser registrada.
 */
void register_string(String s);

/**
 * @brief Remove a string da lista global de strings registradas.
 * 
 * @param string Ponteiro para a String a ser removida.
 */
void unregister_string(String string);


#endif