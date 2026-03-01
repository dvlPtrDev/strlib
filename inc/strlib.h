#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdbool.h>

typedef char *str_ref;
typedef struct String String;

struct String {
    str_ref data;
    size_t length;
    size_t capacity;
    
    void (*string_from)(String *self, const str_ref s);
};


// protótipos
String new_string(size_t with_capacity);
void string_from(String *self, str_ref s);
void drop_string(String *string);
void drop_ref(str_ref *ref);
void register_string(String *s);
void unregister_string(String *string, bool remove_string_too);
void clean_str();

// metodos
size_t str_length(str_ref s);

#endif