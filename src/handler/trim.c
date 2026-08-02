#include "include/strlib/strlib.h"
#include <memory.h>
#include <ctype.h>

void trim_str(mut_str s) {
    if (!s || str_len(s, false) == 0) {
        return;
    }
    char *start = s;
    char *end = s + str_len(s, false) - 1;
    while (isspace((unsigned char) *start)) start++;
    while (end >= start && isspace((unsigned char) *end)) {
        *end = '\0';
        end--;
    }
    if (start != s) {
        memmove((void*)s, start, end - start + 2);
    }
} 