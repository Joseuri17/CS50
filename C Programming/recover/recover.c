#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int count = 0;
    //renaming unit8 a type called BYTE
    typedef uint8_t BYTE;
    //setting typer BYTE to buffer
    BYTE buffer[512];
    char *filename = malloc(sizeof(char) * 8);

    FILE *img = NULL;
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    while (fread(buffer, 1, 512, input) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {

            if (count == 0)
            {
                //declraring 000.jpg.
                sprintf(filename, "%03i.jpg", count);
                // opening a new file declared.
                img = fopen(filename, "w");
                // write to the file that we opened.
                fwrite(&buffer, 1, 512, img);
                count++;
            }
            else
            {
                fclose(img);
                //declraring 000.jpg.
                sprintf(filename, "%03i.jpg", count);
                // opening a new file declared.
                img = fopen(filename, "w");
                // close the file youve been writing too.
                fwrite(&buffer, 1, 512, img);
                count++;
            }
        }
        else if (img != NULL)
        {
            fwrite(&buffer, 1, 512, img);
        }
    }

    free(filename);
    fclose(input);
    fclose(img);
}