#ifndef DISPLAY_H
#define DISPLAY_H

#include "../inc/strlib.h"

/* ===========================================
 * Funções de exibição e logging
 * =========================================== */

/**
 * @brief Exibe uma mensagem fatal e encerra o programa.
 * 
 * @param msg Mensagem.
 * @param exit_status Código de saída.
 */
void fatal_print(str_ref msg, size_t exit_status);

/**
 * @brief Exibe uma mensagem de erro sem encerrar o programa.
 * 
 * @param msg Mensagem.
 */
void error_print(str_ref msg);

/**
 * @brief Exibe uma mensagem de debug.
 * 
 * @param msg Mensagem.
 */
void debug_print(str_ref msg);

#endif 