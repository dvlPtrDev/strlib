#include "internal/display.h"
#include "internal/memory.h"
#include "include/strlib/strlib.h"


#define MAX_STRINGS 1024 

static String string_pool[MAX_STRINGS];
static size_t counter = 0;

void register_string(String s)
{
    if (counter < MAX_STRINGS) string_pool[counter++] = s;
    else fatal_print("Maximum number of registered strings exceeded, Increase MAX_STRINGS or clear the heap.", 0x1200);
}

void destroy(String s) {
    deallocate((void**)&s->data);
    deallocate((void**)&s);
}

void unregister_string(String string)
{

    for (size_t i = 0; i < counter; i++)
    {
        if (string_pool[i]->data == string->data)
        {   
            destroy(string_pool[i]);
            // Shift das strings para preencher o espaço
            for (size_t j = i; j + 1 < counter; j++)
            {
                string_pool[j] = string_pool[j + 1];
            }            
            string_pool[--counter] = NULL;
            break;
        }
    }
}

void clean_str() {
    while (counter > 0) unregister_string(string_pool[0]);   
}
