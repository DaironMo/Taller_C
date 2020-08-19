#include <stdio.h>

// Funciton declaration
void replace(char ch, FILE* filePointer);

int main()
{
    FILE *filePointer;
    char ch;
    int counter = 0;

    filePointer = fopen("biblia.txt", "r+");

    while ((ch = fgetc(filePointer)) != EOF)
    {
        if( ch == 'A' ) {
            ch = 'E';
            replace(ch, filePointer);
            counter++;
        }
        if( ch == 'a' ) {
            ch = 'i';
            replace(ch, filePointer);
            counter++;
        }
    }

    fclose(filePointer);

    printf("Cantidad de caracteres reemplazados: %d\n", counter);

    return 0;
}

void replace(char ch, FILE* filePointer){
    // set file pointer position to previous position, so we can replace actual character
    fseek(filePointer, ftell(filePointer) - 1, SEEK_SET);

    // Replace
    fputc(ch, filePointer);
}