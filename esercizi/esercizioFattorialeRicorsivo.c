cd #include <stdio.h>

int fattoriale(int n){

	if(n<=1)
		return 1;
	else
		return n*fattoriale(n-1);
	
}

int main(){

	int n;
	printf("inserisci valore di cui desidero sapere fattoriale: ");
	scanf("%d", &n);

	printf("fattoriale vale: %d \n", fattoriale(n));

	return 0;
}