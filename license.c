#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        //allocate memory to each pointer
        plates[idx] = malloc(7 * sizeof(char));

        //copy buffer into plates array
        strcpy(plates[idx], buffer);
        idx++;
    }

    //print license plates
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    //free allocated memory
    for (int j = 0; j < 8; j++)
    {
        free(plates[j]);
    }

    fclose(infile);

    return 0;
}
