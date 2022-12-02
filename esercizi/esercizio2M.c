#include <stdio.h>

int main(){

		int n, k;

		printf ("inserisci valore base: ");
		scanf("%d", &k);

		printf("inserisci valore esponente massimo: ");
		scanf("%d", &n);

	int sommatoria = 0 ;
	int prodotto_parziale = k;

		for(int i=0; i<n; i++){
		//IN QUESTO MODO MI EVITO UN CICLO FOR ANNIDATO TRAMITE 			L'USO DI UNA PROPRIETA' DELLE SERIE ESPONENZIALI (POICHE' 		DEFINITO K(X) IL VALORE DI K^X, K(X+1) NON E' CHE K(X)*X)

			sommatoria += prodotto_parziale;
			prodotto_parziale*=k;
		
		}
	
		printf("sommatoria vale: %d \n", sommatoria);

	return 0;
}