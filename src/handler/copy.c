#include "include/strlib/strlib.h"

void copy_str(mut_str dest, str src, size_t bytes) 
{

    if (!bytes) bytes = str_len(src, true);
    const char *srcp = src;
    
    for (char *destp = dest; bytes--; srcp++, destp++) *destp = *srcp;
}