#include <strlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void test_string_functions(void) {
    String s1 = new_string(10);
    s1.string_from(&s1, "Hello");
    String s2 = new_string(20);
    string_copy(s2.data, s1.data, 0);
    string_concat(&s1, "!!!");
    replace_char(s1.data, 'l', 'x');

    assert(!string_compare(s1.data, s2.data));
    assert(string_compare("Hexxo!!!", s1.data)); // ajusta se necessário

    unregister_string(&s1);
    unregister_string(&s2);
}

void test_is_numeric(void) {
    String sn1 = new_string(10);
    String sn2 = new_string(10);
    sn1.string_from(&sn1, "12345");
    sn2.string_from(&sn2, "12a45");
    
    assert(is_numeric(sn1.data));
    assert(!is_numeric(sn2.data));
    
    unregister_string(&sn1);
    unregister_string(&sn2);
}

int main(void) {
    printf("=== Rodando testes ===\n");

    test_string_functions();
    test_is_numeric();

    printf("Todos os testes passaram!\n");
    return 0;
}