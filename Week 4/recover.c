#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<cs50.h>

#define BLOCK 512
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Error checking
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the file + initialize variables
    FILE *file = fopen(argv[1], "r");

    // Error check the file
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    FILE *holder;
    BYTE buffer[BLOCK];
    char filename[8];
    int count = 0;

    while (fread(buffer, sizeof(buffer), 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(holder);
                sprintf(filename, "%03d.jpg", count);
                count++;

                holder = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, holder);

            }

            if (count == 0)
            {
                sprintf(filename, "%03d.jpg", count);
                count++;

                holder = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, holder);
            }
        }

        else if (count > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, holder);
        }
    }

    fclose(holder);
    fclose(file);
    return 0;
}