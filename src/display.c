#include "../internal/display.h"
#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Esse arquivo é um helper usado no debug, a biblioteca strlib não usa e não deve nenhuma função aqui presente
 * @note *EXCETO* a função fatal_print
 */
void fatal_print(str msg, size_t exit_status)
{
    fprintf(stderr, "\x1b[031m[FATAL] %s\n[STATUS] %zu", msg, exit_status);
    exit(exit_status);
}

void error_print(str msg)
{
    fprintf(stderr, "\x1b[031m[ERROR] %s", msg);
}

void debug_print(str msg)
{
    printf("\x1b[033m[DEBUG] %s\x1b[0m", msg);
}
