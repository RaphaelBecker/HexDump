//TODO: declare hexdump function which is implemented in hexdump.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hexdump(FILE *input, FILE *output);

int main(int argc, char *argv[])
{
    //TODO: handle arguments and call hexdump

FILE *input;
    // Dateizeiger erstellen (file handler)
 
    if (argc < 1)
    {
    return 1;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            input = fopen(argv[i], "rb");
            if (input == NULL){
                return 1;
            }
            else { 
            hexdump(input, stdout);
            fprintf(stdout, "\n"); 
             fclose(input);}
        }
        // Datei schliessen
    }
    return 0;
}

// FILE* f;
// if(argv[1] == NULL) printf("Keine Datei ausgewaehlt.\n");
// f = fopen(argv[1],"r");
// if(f == NULL) printf("Keine Datei vorhanden.\n");
// while(fgets(str,256,f) != NULL) printf("%s",str);

// if(argv[2] == NULL) printf("Keine Datei ausgewaehlt.\n");
// f = fopen(argv[2],"r");
// if(f == NULL) printf("Keine Datei vorhanden.\n");
// while(fgets(str,256,f) != NULL) printf("%s",str);

// fclose(f);
// system("PAUSE");
// return 0;
// }
