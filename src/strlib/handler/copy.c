#include "../../../include/strlib.h"

void string_copy(mut_str dest, str src, size_t bytes) 
{
    if (!bytes) bytes = string_length(src, true);
    for (size_t i = 0; i < bytes; i++) {
        dest[i] = src[i];
    }
}