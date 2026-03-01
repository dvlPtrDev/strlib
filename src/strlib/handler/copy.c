#include "../../../inc/strlib.h"

void string_copy(str dest, str src, size_t bytes) 
{
    if (!bytes) bytes = string_length(src, false);
    for (size_t i = 0; i < bytes; i++) {
        dest[i] = src[i];
    }
    dest[bytes] = '\0';
}