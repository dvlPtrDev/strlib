#include "include/strlib/strlib.h"

bool is_numeric(str value) 
{
    size_t len = str_len(value, false);
    for (size_t i = 0; i < len; i++) {
        char c = value[i];
        if (c < '0' || c > '9') {
            return false;
        } 
    }    
    return true;
}
