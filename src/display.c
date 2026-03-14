#include "../internal/display.h"
#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Helper usado no debug.
 * @note A biblioteca usa a função fatal_print para *Matar* o programa em erros **IRRECUPERÁVEIS**
 */
void fatal_print(str msg, size_t exit_status)
{
    fprintf(stderr, "\x1b[031m[FATAL] %s\n[STATUS] %zu", msg, exit_status);
    exit(exit_status);
}


void debug_print(str msg)
{
    printf("\x1b[033m[DEBUG] %s\x1b[0m", msg);
}
