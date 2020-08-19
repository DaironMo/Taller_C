#include <stdio.h>
#include <gmp.h>

// Functions declarations
void handle( mpz_t n );
int esPerfecto( int n );

int main(){

    mpz_t num;

    // Initialize num
    mpz_init(num);
    mpz_set_ui(num, 0);

    printf("Digite cantidad: ");
    mpz_inp_str(num, stdin, 10);        // Read through stdin, in base 10 and assign value to num

    handle(num);

    return 0;
}

void handle( mpz_t n ){

    int counter = 0;
    int i=0;

    while(counter < mpz_get_ui(n)){
        if( esPerfecto(i) ) {
            printf("%d\n", i);
            counter++;
        }

        i++;
    }

}

int esPerfecto( int n ){

    int acum = 0;

    for (int i = 1; i <= (n/2); i++)
    {
        if( n%i == 0 ) acum += i;
    }

    if( acum == n ) return 1;

    return 0;    
}
