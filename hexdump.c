
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 16
unsigned char buffer[BUFFERSIZE];

void hexdump(FILE *input, FILE *output)
{

    size_t bytes_read = 0;
    unsigned int lines = 0, pufOffset = 0, i, tab;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFERSIZE, input)) > 0)
    {
        pufOffset = lines * BUFFERSIZE;
        fprintf(output, "%06x : ", pufOffset);
        lines++;
        for (i = 0; i < bytes_read; i++)
        {
            fprintf(output, "%02x ", buffer[i]);
        }
        for (tab = 0; tab < (BUFFERSIZE - bytes_read); tab++)
        {
            fprintf(output, "   ");
        }
        fprintf(output, "  ");

        for (i = 0; i < bytes_read; i++)
        {
            if (isprint(buffer[i]))
            {
                fprintf(output, "%c", buffer[i]);
            }
            else
            {
                fprintf(output, ".");
            }
        }
         fprintf(output, "\n");
        if (feof(input))
            break;
    }
}