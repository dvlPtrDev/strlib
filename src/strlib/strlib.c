#include "../../include/strlib.h"
#include "../../include/memory.h"

#include <stdlib.h>

size_t recalc_capacity(size_t capacity, size_t min_capacity)
{
    size_t new_capacity = capacity != 0 ? capacity : 1; // Garante que não aconteça 0 * 2
    while (new_capacity < min_capacity)
    {
        new_capacity *= 2;
    }
    return new_capacity;
}

void string_from(String *self, str s) 
{
    size_t len = string_length(s, true);

    if (self->data)
    {
        unregister_string(self, false);
    }

    if (isPointerNull(self->data, false) || self->capacity < len)
    {
        self->capacity = recalc_capacity(self->capacity, len);
        self->data = allocate(self->data, self->capacity);
    }

    self->length = len - 1; // exclui o null terminator
    string_copy(self->data, s, len); // atribuição de memcpy    

    register_string(self);
}

String new_string(size_t with_capacity)
{
    with_capacity++; // reserva espaço para null terminator
    String self;
    self.data = allocate(NULL, with_capacity);
    self.data[0] = '\0';
    self.length = 0;               // quantos caracteres estão alocados
    self.capacity = with_capacity; // quantos bytes a string consegue comportar sem realocar
    self.string_from = string_from;
    return self;
}
void drop_string(String *string)
{
    if (string->data)
    {
        free(string->data);
        string->data = NULL;
    }

    string->string_from = NULL;
    string->capacity = 0;
    string->length = 0;
}

void drop_ref(mut_str *ref)
{
    if (isPointerNull(*ref, false))
        return;

    free(*ref);
    *ref = NULL;
}