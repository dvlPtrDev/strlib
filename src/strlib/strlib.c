#include "../../inc/strlib.h"
#include "../../inc/memory.h"
#include <string.h>

static size_t recalc_capacity(size_t capacity, size_t min_capacity);

void string_from(String *self, str_ref s)
{
    size_t len = str_length(s) + 1;

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
    memcpy(self->data, s, len);
    register_string(self);
}

String new_string(size_t with_capacity)
{
    with_capacity++;
    String self;
    self.data = allocate(NULL, with_capacity);
    self.data[0] = '\0';
    self.length = 0;               // quantos caracteres estão alocados no momento
    self.capacity = with_capacity; // quantos bytes a string consegue comportar sem realocar
    self.string_from = string_from;
    return self;
}

#include <stdlib.h>
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
void drop_ref(str_ref *ref)
{
    if (isPointerNull(*ref, false))
        return;
    free(*ref);
    *ref = NULL;
}

static size_t recalc_capacity(
    size_t capacity,
    size_t min_capacity)
{

    size_t new_capacity = capacity != 0 ? capacity : 1; // Garante que não aconteça 0 * 2
    while (new_capacity < min_capacity)
    {
        new_capacity *= 2;
    }
    return new_capacity;
}
