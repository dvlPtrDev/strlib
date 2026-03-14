#include <strlib.h>

bool string_compare(str s1, str s2) {
    const char *p1 = s1, *p2 = s2;
    while (*p1 && *p2) {
        if (*p1 != *p2) return false;
        p1++, p2++;
    }
    return *p1 == *p2;
}