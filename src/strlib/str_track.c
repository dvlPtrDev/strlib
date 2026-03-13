#include "../../include/strlib.h"
#include "../../internal/display.h"
#include "../../include/memory.h"

#define MAX_STRINGS 1024 

static String *all_strings[MAX_STRINGS];
static __uint16_t counter = 0;

void register_string(String *s)
{
    if (counter < MAX_STRINGS)
    {
        all_strings[counter++] = s;
    }
    else
    {
        fatal_print("This program uses 1024 Strings, fix that code!", 0x1100);
    }
}

void unregister_string(String *string, bool remove_string_too)
{
    for (__uint16_t i = 0; i < counter; i++)
    {
        if (all_strings[i]->data == string->data)
        {
            if (remove_string_too) drop_string(string);
            else drop_ref(&all_strings[i]->data);

            // Shift das strings para preencher o espaço
            for (__uint16_t j = i; j < counter - 1; j++)
            {
                all_strings[j] = all_strings[j + 1];
            }

            counter--;
            all_strings[counter] = NULL;
            break;
        }
    }
}

void clean_str()
{
    while (counter > 0)
    {
        unregister_string(all_strings[0], true);
    }
}