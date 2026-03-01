#include "../inc/strlib.h"

int main(void) {
    String s1 = new_string(10);
    String s2 = new_string(5);

    s1.string_from(&s1, "Hello");
    s2.string_from(&s2, "World");

    printf("s1: %s (len: %zu, cap: %zu)\n", s1.data, s1.length, s1.capacity);
    printf("s2: %s (len: %zu, cap: %zu)\n", s2.data, s2.length, s2.capacity);

    s1.string_from(&s1, "A much longer string to test realocation");
    s2.string_from(&s2, "Hi");

    printf("After update:\n");
    printf("s1: %s (len: %zu, cap: %zu)\n", s1.data, s1.length, s1.capacity);
    printf("s2: %s (len: %zu, cap: %zu)\n", s2.data, s2.length, s2.capacity);
    
    clean_str();
}