#include <stdio.h>

int positivo(int x){

	return (x>=0);
	
}

int pari(int x){

	return (x%2==0);
	
}

int somma(int x, int y){

	return x+y;
	
}

int modulo(int x){

	if(!positivo(x))
		return -x;
	
	return x;
	
}

void stampaMigliore(int x){

	if(!positivo(x))
		printf(" -%d ",x);
	else
		printf(" +%d ",x);
	
}

int sommaMassima(int x, int y){

	return somma(modulo(x), modulo(y));
	
}

void stampaSommaMassima(int x, int y){
	
	printf("somma massima vale: ");
	stampaMigliore(x);
	stampaMigliore(y);
	printf("= %d \n", sommaMassima(x,y));
	
}

void stampaTutto(int x, int y){

	if(positivo(x))
		printf("%d è positivo\n", x);
	else
		printf("%d è negativo\n", x);

	if(pari(y))
		printf("%d è pari\n", y);
	else
		printf("%d è dispari\n",y);

	stampaSommaMassima(x,y);

	
}
int main(){

	int a, b;
	printf("inserisci valore di a: ");
	scanf("%d", &a);
	printf("inserisci valore di b: ");
	scanf("%d", &b);

	stampaTutto(a,b);

	return 0;
}