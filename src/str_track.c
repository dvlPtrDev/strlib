#include "../internal/display.h"

#include <strlib.h>
#include <memory.h>

#define MAX_STRINGS 1024 

static String *string_pool[MAX_STRINGS];
static __uint16_t counter = 0;

void register_string(String *s)
{
    if (counter < MAX_STRINGS) string_pool[counter++] = s;
    else fatal_print("This program uses more than MAX_STRINGS allows, fix that or change MAX_STRINGS!", 0x1200);
}

void unregister_string(String *string)
{

    for (__uint16_t i = 0; i < counter; i++)
    {
        if (string_pool[i]->data == string->data)
        {
            // Shift das strings para preencher o espaço
            for (__uint16_t j = i; j + 1 < counter; j++)
            {
                string_pool[j] = string_pool[j + 1];
            }            
            string_pool[--counter] = NULL;
            break;
        }
    }
}

void clean_str()
{
    while (counter > 0) unregister_string(string_pool[0]);   
}