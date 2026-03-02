#include "../../../include/strlib.h"
#include "../../../include/memory.h"
#include <stdarg.h>

String vformat(str msg, va_list args) 
{
    int needed = get_total_len(args, msg);
    String s = new_string(needed);

    vsnprintf(s.data, needed, msg, args);
        
    s.length = needed - 1;
    register_string(&s);
    return s;
}

int get_total_len(va_list args, str s) {
    va_list copy;
    va_copy(copy, args);
    int n = vsnprintf(NULL, 0, s, copy) + 1; // consome a cópia, retorna os bytes necessários + \0
    va_end(copy);
    
    return n; 
}