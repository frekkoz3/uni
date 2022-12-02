#include <stdio.h>

int fibonacci (int n){

	if (n==0)	//CASO BASE F(O)
		return 0;
	if(n==1)	//CASO BASE F(1)
		return 1;

	return fibonacci(n-1)+fibonacci(n-2); //CASO GENERICO F(N)
	
}

int main(){

	int n;
	printf("inserisci il valore n: ");
	scanf("%d", &n);

	printf("il valore n-esimo della serie di fibonacci vale %d \n", fibonacci(n));

	return 0;
}