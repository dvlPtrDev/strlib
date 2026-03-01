#include "../../../inc/strlib.h"
#include <stdbool.h>


size_t string_length(str string, bool return_terminator)
{
    size_t i = 0;
    while (string[i] != '\0')
        i++;

    if (return_terminator)
        return i + 1; // inclui o null terminator

    return i;
}