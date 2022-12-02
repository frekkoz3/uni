#include <stdio.h>

int fibonacci (int n){

	if (n==0)	//CASO BASE F(O)
	{
		printf("+0 ");
		return 0;
	}
		
	if(n==1)	//CASO BASE F(1)
	{
		printf("+1 ");
		return 1;
	}
		
	return fibonacci(n-1)+fibonacci(n-2); //CASO GENERICO F(N)
	
}

int fibonacciSoloValore (int n){
	
	if (n==0)	//CASO BASE F(O)
		return 0;
	if(n==1)	//CASO BASE F(1)
		return 1;

	return fibonacciSoloValore(n-1)+fibonacciSoloValore(n-2); //CASO GENERICO F(N)
}

int main(){

	int n;
	printf("inserisci il valore n: ");
	scanf("%d", &n);

	printf("serie di fibonacci ");
	int j = fibonacci(n);
	printf("= %d \n", fibonacciSoloValore(n));

	return 0;
}