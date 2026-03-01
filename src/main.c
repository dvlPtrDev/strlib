#include <stdio.h>
#include "../inc/strlib.h"

int main(void) {
    String string_prototype = new_string(20);
    string_prototype.string_from(&string_prototype, "Test!12345678");
    printf("%s\n", string_prototype.data);
    printf("%zu\n", string_prototype.length);
}