#include "include/strlib/strlib.h"
#include "internal/memory.h"

void push_str(String self, char c) {
    ensure_string_capacity(self, self->length + 2);
    self->data[self->length++] = c;
    self->data[self->length] = '\0';
}