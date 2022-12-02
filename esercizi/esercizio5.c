#include <stdio.h>

int main(){

	int n, k;

	printf("inserisci n: ");
	scanf("%d", &n);

	printf("inserisci k: ");
	scanf("%d", &k);

	if(n<k)	//CASO N<K PER DEFINIZIONE VALE 0
		printf("il coefficiente binomiale di n sopra k vale 0 \n");
	else{
		
		int fattorialeNfinoaK = 1;	//DALLA FUNZIONE DI CALCOLO IO OTTENGO CHE IL NUMERATORE DELLA FRAZIONE E' (N*N-1*N-2...*N-K)
		for(int i=0; i<(n-k);i++)
			fattorialeNfinoaK *= (n-i);
		int fattorialeNmenoK = 1;	//DALLA FUNZIONE DI CALCOLO IO OTTENGO CHE IL DENOMINATORE DELLA FRAZIONE E' (N-K*N-K-1*N-K-2...*1)
		for(int i=(n-k); i>0; i--)
			fattorialeNmenoK *= i;
		printf("il coefficiente binomiale di n sopra k vale %d \n", fattorialeNfinoaK/fattorialeNmenoK);
		
	}
		

	return 0;
}