#include "../../inc/strlib.h"
#include "../../inc/memory.h"
#include <string.h>
#include <stdio.h>

static size_t __recalc_capacity(size_t capacity, size_t min_capacity); 
    
void string_from(String *self, str_ref s) {
    size_t len = strlen(s);

    self->capacity = __recalc_capacity(self->capacity, len + 1);
    self->data = allocate(self->data, self->capacity);
    self->length = len; 
    strcpy(self->data, s);
}

String new_string(size_t with_capacity) {
    with_capacity++;
    String self;
    self.data = allocate(NULL, with_capacity);
    self.length = 0; // quantos caracteres estão alocados no momento
    self.capacity = with_capacity; // quantos bytes a string consegue comportar sem realocar
    self.string_from = string_from;
    return self;
}  

static size_t __recalc_capacity
    (
        size_t capacity, 
        size_t min_capacity
    ) { 

    size_t new_capacity = capacity != 0 ? capacity : 1; // Garante que não aconteça 0 * 2 
    while (new_capacity < min_capacity) {
        printf("Minimum capacity = %zu\ncapacity: %zu", min_capacity, new_capacity);
        new_capacity *= 2;
        printf("Relocating to: %zu\n", new_capacity);
    }
    return new_capacity;
}