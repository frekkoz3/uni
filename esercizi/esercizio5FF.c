#include <stdio.h>

int coefficienteBinomiale(int n, int k){

	int n_f = 1;
	int k_f = 1; 
	int n_k_f = 1;

	for(int i=n; i>=1; i--){

		if (i <= k)
			k_f *= i;
		if (i <= n-k)
			n_k_f *= i;
		n_f *= i;
		
	}
	printf("n_f vale %d \n", n_f);
	printf("k_f vale %d \n", k_f);
	printf("n_k_f vale %d \n", n_k_f);
	return n_f/(k_f * n_k_f);
	
}

int main(){

	int n, k;

	printf("inserisci n: ");
	scanf("%d", &n);

	printf("inserisci k: ");
	scanf("%d", &k);

	if(n<k)
		printf("il coefficiente binomiale di n sopra k vale: %d \n", 0);
	else
		printf("il coefficiente binomiale di n sopra k vale: %d \n", coefficienteBinomiale(n,k));
	
	return 0;
}