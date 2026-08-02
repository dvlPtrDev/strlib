#include "include/strlib/strlib.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void test_string_functions(void) {
    String s1 = new_string(10);
    string_from(s1, "     Hello");
    String s2 = new_string(20);
    copy_str(s2->data, s1->data, 0);
    concat_str(s1, "!!!       ");
    replace_str(s1->data, 'l', 'x');
    trim_str(s1->data);

    assert(!compare_str(s1->data, s2->data));
    assert(compare_str("Hexxo!!!", s1->data)); // ajusta se necessário

}

void test_is_numeric(void) {
    String sn1 = new_string(10);
    String sn2 = new_string(10);
    string_from(sn1, "12345");
    string_from(sn2, "12a45");
    
    assert(is_numeric(sn1->data));
    assert(!is_numeric(sn2->data));
}

void test_read_line_str(void) {
    printf("Digite algo: ");
    String s1 = read_line_str();
    printf("%s\n", s1->data);
    printf("%zu\n", s1->length);
    printf("%zu\n", s1->capacity);
    printf("%p\n", s1);
}
int main(void) {
    printf("=== Rodando testes ===\n");

    test_string_functions();
    test_is_numeric();
    test_read_line_str();
    
    printf("Todos os testes passaram!\n");
    clean_str();
    return 0;
}
