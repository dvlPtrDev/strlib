#include "../../../inc/strlib.h"

size_t str_length(str_ref s) {
    size_t i = 0;
    while (s[i] != '\0') i++;
    return i;
}