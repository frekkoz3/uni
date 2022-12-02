#include <stdio.h>

int main(){

		int n, k;

		printf ("inserisci valore base: ");
		scanf("%d", &k);

		printf("inserisci valore esponente massimo: ");
		scanf("%d", &n);

	int sommatoria = 0 ;

		for(int i=0; i<n; i++){

			int prodotto_parziale = k;
		
			for(int j=0; j<i; j++){

				prodotto_parziale*=k;
	
			}

			sommatoria += prodotto_parziale;
		
		}
	
		printf("sommatoria vale: %d \n", sommatoria);

	return 0;
}