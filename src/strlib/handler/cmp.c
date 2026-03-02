#include "../../../include/strlib.h"

bool string_compare(str s1, str s2) {
    size_t len1 = string_length(s1, false); 
    size_t len2 = string_length(s2, false); 

    if (len1 != len2) return false;
    for (size_t i = 0; i < len1; i++) 
    {
        if (s1[i] != s2[i]) return false;        
    }
    return true;
}