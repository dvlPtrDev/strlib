#include <strlib.h>

void string_copy(mut_str dest, str src, size_t bytes) 
{

    if (!bytes) bytes = string_length(src, true);
    const char *srcp = src;
    
    for (char *destp = dest; bytes--; srcp++, destp++) *destp = *srcp;
}