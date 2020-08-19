#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
int sonPalindromas(char[]);

int main(){

    char word[100];

    printf("Digite palabra: ");
    gets(word);

    if( sonPalindromas(word) ){
        printf("Es Palindroma\n");
    }else{
        printf("NO Es Palindroma\n");
    }

    return 0;
}

int sonPalindromas(char word[]){

    int words_length = strlen(word);
    char reverse[words_length];
    char formatted_word[words_length];
    int j;

    // get reverse string
    j = 0;
    for(int i = words_length-1; i >= 0; i--){
        if( word[i] != ' ' ){
            reverse[j] = word[i];
            j++;
        }
    }
    
    // remove spaces from original string
    j = 0;
    for(int i = 0; i < words_length; i++){
        if( word[i] != ' ' ){
            formatted_word[j] = word[i];
            j++;
        }
    }

    // Check
    for(int i = 0; i < words_length; i++){
        if( tolower(formatted_word[i]) != tolower(reverse[i]) ){
            return 0;
        }
    }

    return 1;
}