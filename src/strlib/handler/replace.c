#include "../../../include/strlib.h"

void replace_char(mut_str s, char reject, char replace)
{
    for (mut_str p = s; *p; p++) {
        if (*p == reject) *p = replace;
    }
}