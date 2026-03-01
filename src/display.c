#include <stdio.h>
#include <stdlib.h>
#include "../inc/display.h"

void fatal_err(str_ref msg, size_t exit_status) {
    fprintf(stderr, "\x1b[033m[ERROR] %s\n[STATUS] %zu", msg, exit_status);
    exit(exit_status);
}
