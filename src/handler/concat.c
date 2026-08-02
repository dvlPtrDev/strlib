#include "include/strlib/strlib.h"
#include "internal/memory.h"


void concat_str(String dest, str src)
{
    size_t dest_len = dest->length;
    size_t src_len = str_len(src, false);
    size_t total = dest_len + src_len;

    dest->capacity = recalc_capacity(dest->capacity, total + 1);
    dest->data = allocate(dest->data, dest->capacity);

    copy_str(dest->data + dest_len, src, src_len + 1);
    dest->length = total;
}