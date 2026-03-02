#include "../../../include/strlib.h"
#include "../../../include/memory.h"

void string_concat(String *dest, str src)
{
    size_t dest_len = string_length(dest->data, false);
    size_t src_len = string_length(src, false);
    size_t total = dest_len + src_len;

    dest->capacity = recalc_capacity(dest->capacity, total + 1);
    dest->data = allocate(dest->data, dest->capacity);
    
    
    for (size_t i = 0; i < src_len; i++) {
        dest->data[dest_len + i] = src[i]; 
    }
    dest->data[total] = '\0';
    dest->length = total;
}