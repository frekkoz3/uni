#include <stdio.h>

int potenzaRicorsiva (int base, int esponente){

	if(esponente == 0)
		return 1;
	return base * potenzaRicorsiva(base, esponente-1);
	
}

int sommatoria(int n){

	if(n == 0)
		return 0;
	return n + sommatoria(n-1);
	
}

int main(){

	int n;
	printf("inserisci n: ");
	scanf("%d", &n);
	printf("la sommatoria vale : %d \n", potenzaRicorsiva(2, n)*sommatoria(n));

	return 0;
}