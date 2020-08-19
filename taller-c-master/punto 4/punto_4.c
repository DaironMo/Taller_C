#include <stdio.h>

#define MAX 100

//convierte las mayusculas a minusculas.
int convertirMayusculas(char s[]);
//elimina los espacios de una cadena y devuelve el tamaño con el que quedo el string.
int eliminarEspacios(char s[],int len);
//Cuenta el tamaña de una cadena.
int tamCadena(char s[]);
//Son palindromas;
int isPalindroma(char s[],int len);

int main()
{
	char s[MAX];
	char s2[MAX];
	int i,j;
	int len,len2;
	printf("Palabra 1:\n");
	scanf("%s",s);
	printf("palabra 2:\n");
	scanf("%s",s2);

	len = tamCadena(s);
	len2 = tamCadena(s2);	
	convertirMayusculas(s);
	convertirMayusculas(s2);

	len = eliminarEspacios(s,len);
	len2 = eliminarEspacios(s2,len2);
	
	if(isPalindroma(s,len) && isPalindroma(s2,len2)){
		printf("Son palidromas\n");
	}else{
		printf("No son palindromas\n");
	}

	return 1;
}

int isPalindroma(char s[],int len)
{
	int i,j;
	for(i = 0; i<len-2;i++){
		if(s[i] != s[len-i-2]){
			return 0;
		}
	}

	return 1;
}

int eliminarEspacios(char s[],int len)
{
	int i,j;
	char sc[len];
	for(i = 0,j=0; i< len; i++){
		if(s[i]!=' '){
			s[j] = s[i];
			j++;
		}
	}

	return j;
}

int tamCadena(char s[]){
	int i=0;
	while(s[i] != '\0'){
		i++;
	}
	if(s[i] == '\0'){
		i++;
	}
	
	return i;
}

int convertirMayusculas(char s[]){
	int i=0;
	char c=0;
	while((c=s[i]) != '\0'){
		if(c > 64 && c < 91){
			s[i] = c + 32;
		}
		i++;
	}
}