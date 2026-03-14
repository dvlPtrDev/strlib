#include <strlib.h>
#include <stdbool.h>


size_t string_length(str string, bool return_terminator)
{
    size_t i = 0;
    while (string[i] != '\0')
        i++;

    if (return_terminator)
        i++; // inclui o null terminator

    return i;
}