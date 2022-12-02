#include <stdio.h>

int fattoriale(int a, int b){ //QUESTA FUNZIONE CALCOLA IL FATTORIALE ALL'INTERNO DI UN RANGE BEN DEFINITO CHE VA DA A (MIN) a B(MAX)
	
	int parziale = 1;

	for(int i=b; i>a; i--)
		parziale*=i;

	return parziale;
}

int main(){

	int n, k;

	printf("inserisci n: ");
	scanf("%d", &n);

	printf("inserisci k: ");
	scanf("%d", &k);

	if(n<k)	//CASO N<K PER DEFINIZIONE VALE 0
		printf("il coefficiente binomiale di n sopra k vale 0 \n");
	else{
		
		int fattorialeNfinoaK = fattoriale(k, n);	//DALLA FUNZIONE DI CALCOLO IO OTTENGO CHE IL NUMERATORE DELLA FRAZIONE E' (N*N-1*N-2...*N-K)
		printf("fattorialeNfinoaK vale %d \n", fattorialeNfinoaK);
		int fattorialeNmenoK = (1, (n-k));	//DALLA FUNZIONE DI CALCOLO IO OTTENGO CHE IL DENOMINATORE DELLA FRAZIONE E' (N-K*N-K-1*N-K-2...*1)
		printf("fattorialeNmenoK vale %d \n", fattorialeNmenoK);
		printf("il coefficiente binomiale di n sopra k vale %d \n", fattorialeNfinoaK/fattorialeNmenoK);
		
	}
		

	return 0;
}