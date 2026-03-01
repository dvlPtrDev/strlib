#include "../../../inc/strlib.h"
#include <stdbool.h>


size_t str_length(str_ref s, bool return_terminator)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;

    if (return_terminator)
        return i + 1; // inclui o null terminator

    return i;
}