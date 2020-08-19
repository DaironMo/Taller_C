#include <stdio.h>
#include <string.h>

void main()
{
    FILE *fp;
    char buff[ 255 ] = " ";
    char *line;
    const char divider[2] = " ";
    int counter = 0;

    fp = fopen("biblia.txt", "r");

    // iterates each file lines
    while ((fgets(buff, 255 , (FILE*)fp)) != NULL)
    {
        line = strtok(buff, divider);

        // iterates each line words
        while(line != NULL){
            // first letter of word is 'a' or 'A', then counter++
            //if( (line[0] == 'a' || line[0] == 'A') && strlen(line) >= 3 ) counter++;
            if( line[0] == 'a' && strlen(line) >= 3 ) counter++;

            line = strtok(NULL, divider);
        }
    }

    printf("cantidad: %d\n", counter);

    fclose(fp);
}