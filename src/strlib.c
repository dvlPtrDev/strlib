#include "internal/display.h"
#include "internal/memory.h"
#include "include/strlib/strlib.h"
#include "internal/registry.h"

void string_from(String self, str s) 
{
    size_t len = str_len(s, true);

    ensure_string_capacity(self, len);
    self->length = len-1; // exclui o null terminator
    copy_str(self->data, s, len); // Copia o conteúdo pra memória exatamente com os caracteres    
}

String new_string(size_t with_capacity)
{
    size_t capacity_with_terminator = with_capacity + 1; // reserva espaço para null terminator

    String self = allocate(NULL, sizeof(*self));
    self->data = allocate(NULL, capacity_with_terminator);
    if (!self->data) fatal_print("Can't allocate sufficient bytes for this string!", 0x1100);
    self->data[0] = '\0';
    
    self->length = 0;               // quantos caracteres estão sendo usados
    self->capacity = capacity_with_terminator; // quantos bytes a string consegue comportar sem realocar
    
    register_string(self);
    return self;
}

void drop_string(String string)
{
    if (string->data)
    {
        deallocate((void**)&string->data);
    }

    string->capacity = 1;
    string->length = 0;
}