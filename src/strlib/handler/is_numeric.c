#include <strlib.h>

bool is_numeric(str value) 
{
    size_t str_len = string_length(value, false);
    for (int i = 0; i < str_len; i++) {
        char c = value[i];
        if (c < '0' || c > '9') {
            return false;
        } 
    }    
    return true;
}