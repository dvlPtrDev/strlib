#ifndef DISPLAY_H
#define DISPLAY_H
    #include "../inc/strlib.h"
    void fatal_print(str_ref msg, size_t exit_status);
    void error_print(str_ref msg);
    void debug_print(str_ref msg);
#endif