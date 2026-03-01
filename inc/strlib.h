#ifndef MY_STRING_H
#define MY_STRING_H
typedef char *str_ref;
typedef struct String String;

#include <stdio.h>

struct String {
    str_ref data;
    size_t length;
    size_t capacity;

    void (*string_from)(String *self, const str_ref s);
};

// protótipos
String new_string(size_t with_capacity);
void string_from(String *self, str_ref s);
// void string_free(String *s);

#endif