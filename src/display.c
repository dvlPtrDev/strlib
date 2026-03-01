#include "../inc/display.h"
#include <stdio.h>
#include <stdlib.h>

void fatal_print(str_ref msg, size_t exit_status)
{
    fprintf(stderr, "\x1b[031m[FATAL] %s\n[STATUS] %zu", msg, exit_status);
    exit(exit_status);
}

void error_print(str_ref msg)
{
    fprintf(stderr, "\x1b[031m[ERROR] %s", msg);
}

void debug_print(str_ref msg)
{
    printf("\x1b[033m[DEBUG] %s\x1b[0m", msg);
}