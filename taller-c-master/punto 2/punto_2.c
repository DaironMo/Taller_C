#include <stdio.h>
#include <gmp.h>

// Function declaration
void printPrimos( mpz_t n );

int main(){

    char inputStr[1024];
    mpz_t num;

    /* 1. Initialize the number */
    mpz_init(num);
    mpz_set_ui(num,0);

    printf("Digite numero: ");
    mpz_inp_str(num, stdin, 10);        // Read through stdin, in base 10 and assign value to num

    /* Print n */
    printf ("num = ");
    mpz_out_str(stdout,10,num);
    printf ("\n");
    
    printPrimos(num);

    mpz_clear(num);

    return 0;
}

void printPrimos( mpz_t n ){

    mpz_t mod;

    for (int i = 2; mpz_get_ui(n) > 1; i++)
    {
        while(mpz_mod_ui(mod, n, i) == 0){
            
            printf ("%d\n", i);

            mpz_div_ui(n, n, i);
        }
    }
}
