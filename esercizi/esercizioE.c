#include <stdio.h>

int potenza (int base, int esponente){

	int k = base;
	
	if(esponente<=0)
		return 1;
	for(int i=1; i<esponente; i++)
		base*=k;

	return base;
	
}

int fromBinaryToDecimal(int bin){

	int c=0;
	int dec=0;

	do{
		int unità = bin%10;
		dec += (potenza(2,c)*unità);
		c++;
		bin/=10;
	}while(bin>0);
	
	return dec;
	
}

int main(){

	int bin;
	printf("inserisci numero in base binaria: ");
	scanf("%d", &bin);
	printf("%d in base decimale vale %d \n", bin, fromBinaryToDecimal(bin));
	return 0;
}