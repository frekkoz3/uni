#include <stdio.h>
#include <math.h>

int isPrimo(int n, int m){

	if(n<1)	//CASI SPECIALI NUMERI MINORI DI 1
		return 0;
	
	if(n==1)	//CASO SPECIALE DI 1
		return 0;
	
	if(m < sqrt(n))	//SE SONO ARRIVATO AD UN M MINORE DELLA RADICE DI N SENZA MAI USCIRE VUOL DIRE CHE N E' PRIMO
		return 1;
	
	if(n%m==0)
		return 0;
	
	return isPrimo (n, m-1);
	
}

void distanzaMedia(){

	int primo1 = 1;
	int primo2 = 2;
	int distanzaParziale = primo2 - primo1;
	double distanzaTotale = distanzaParziale;
	int contaPrimi = 2;

	printf("%d is Primo \n", 1);
	printf("%d is Primo \n", 2);
	printf("distanzaParziale vale %d \n", distanzaParziale);

	for(int i=3; i<100; i++){
		
		if(isPrimo(i, i-1)){
			primo1 = primo2;
			primo2 = i;
			distanzaParziale = primo2 - primo1;
			distanzaTotale += distanzaParziale;
			contaPrimi++;
			printf("%d is Primo \n", i);
			printf("distanzaParziale vale %d \n", distanzaParziale);
		}
		
	}

	printf("distanza media vale %lf ", distanzaTotale/(contaPrimi-1)); //IL NUMERO DI INTERVALLLI E' UGUALE AL NUMERO DI NUMERI PRIMI -1
	
	
}

int main(){

	int n = 0;

	printf("inserisci n: ");
	scanf("%d", &n);

	if(isPrimo(n,n-1))
		printf("%d is Primo \n", n);
	else
		printf("%d isn't Primo \n", n);

	distanzaMedia();

	return 0;
}