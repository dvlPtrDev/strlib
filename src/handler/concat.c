#include <strlib.h>
#include <memory.h>

void string_concat(String *dest, str src)
{
    size_t dest_len = dest->length;
    size_t src_len = string_length(src, false);
    size_t total = dest_len + src_len;

    dest->capacity = recalc_capacity(dest->capacity, total + 1);
    dest->data = allocate(dest->data, dest->capacity);

    string_copy(dest->data + dest_len, src, src_len + 1);
    dest->length = total;
}