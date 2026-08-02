#include "include/strlib/strlib.h"

void replace_str(mut_str s, char reject, char replace_str)
{
    for (mut_str p = s; *p; p++) {
        if (*p == reject) *p = replace_str;
    }
}