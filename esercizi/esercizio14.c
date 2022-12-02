#include <stdio.h>

int potenzaDi10(int n){

	if(n==0)
		return 1;
	return 10 * potenzaDi10(n-1);
	
}

int esponente(int n){	//è una funzione che calcola l'ordine di grandezza di n in funzione di 10

	if(n<10)
		return 0;
	return 1 + esponente(n/10);
	
}

int inverti (int n){

	int esp = esponente (n);
	int s = 0;

	for(int i=0; i<=esp; i++){

		int m = n%10;
		n /= 10;
		s += m*potenzaDi10(esp-i);
		
	}

	return s;
	
}

int main(){

	int n;
	printf("inserisci n: ");
	scanf("%d", &n);
	printf("numero inverito: %d \n", inverti(n));

	return 0;
}