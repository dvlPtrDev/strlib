#include "include/strlib/strlib.h"

String read_line_str(void)
{
    String buf = new_string(16);
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        push_str(buf, (char)c);
    }

    return buf;
}