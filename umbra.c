#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void subdivider(char *raws)
{
}
int main(void)
{
    FILE *f = fopen("testing.txt", "r");
    char *raws = string_divider(f);
    int index_buffer = 0;
    int capacidad_buffer = 100;
    char *buffer = (char *)malloc(sizeof(char) * capacidad_buffer);
    for (int i = 0; i <= strlen(raws); i++)
    {
        if (isspace(raws[i]) || i >= strlen(raws))
        {
            if (strlen(buffer) == 0)
            {
                continue;
            }
            if (index_buffer >= capacidad_buffer)
            {
                capacidad_buffer = capacidad_buffer * 2;
                buffer = realloc(buffer, capacidad_buffer);
            }

            buffer[index_buffer] = '\0';
            index_buffer = 0;

            printf("%s\n", buffer);

            continue;
        }
        if (index_buffer >= capacidad_buffer)
        {
            capacidad_buffer = capacidad_buffer * 2;
            buffer = realloc(buffer, capacidad_buffer);
        }

        buffer[index_buffer] = raws[i];
        index_buffer++;
    }

    free(buffer);
    free(raws);
}
