#include "../internal/display.h"

#include <strlib.h>
#include <memory.h>

size_t recalc_capacity(size_t capacity, size_t min_capacity)
{
    size_t new_capacity = capacity != 0 ? capacity : 1; 
    // Garante que não aconteça 0 * 2
    for (; new_capacity < min_capacity; new_capacity<<=1); 
    // dobra new_capacity com bitwise, pode ser mais rápida que new_capacity*=2 em alguns casos 
    return new_capacity;
}

void string_from(String *self, str s) 
{
    size_t len = string_length(s, true);
    unregister_string(self);

    if (!self->data || self->capacity < len)
    {
        size_t new_capacity = recalc_capacity(self->capacity, len);
        self->capacity = new_capacity; 

        str new_dataptr = allocate(NULL, self->capacity);
        self->data = (mut_str)new_dataptr; 
    }

    self->length = len-1; // exclui o null terminator
    string_copy(self->data, s, len); // Copia o conteúdo pra memória exatamente com os caracteres    

    register_string(self);
}

String new_string(size_t with_capacity)
{
    size_t capacity_with_terminator = with_capacity + 1; // reserva espaço para null terminator

    String self;
    self.data = allocate(NULL, capacity_with_terminator);
    if (!self.data) fatal_print("Can't allocate sufficient bytes for this string!", 0x1100);
    self.data[0] = '\0';
    
    self.length = 0;               // quantos caracteres estão alocados
    self.capacity = capacity_with_terminator; // quantos bytes a string consegue comportar sem realocar
    self.string_from = string_from;
    
    return self;
}

void drop_string(String *string)
{
    if (string->data)
    {
        deallocate((void**)&string->data);
    }

    string->string_from = NULL;
    string->capacity = 1;
    string->length = 0;
}