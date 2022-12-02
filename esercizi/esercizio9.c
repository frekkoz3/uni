#include <stdio.h>

int potenza(int n){
	
	if(n==0)
		return 1;
	return 2*potenza(n-1);
	
}

double produttoria(int a, int b){

	double prodotto = 1;
	
	for(int i=a; i<=(b/2); i++)
		prodotto *= (potenza (i)/a);

	return prodotto-b;
	
}

int main(){

	int a,b;
	printf("inserisci a: ");
	scanf("%d", &a);
	printf("inserisci b: ");
	scanf("%d", &b);

	printf("2^n vale %d \n", potenza(b));

	printf("produttoria vale %lf \n", produttoria(a, b));

	return 0;
	
}