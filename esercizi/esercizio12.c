#include <stdio.h>

int sommaCifre(int n){

	if( n<10 )
		return n;
	return n%10 + sommaCifre(n/10);
	
}

int main(){

	int n;

	scanf("%d", &n);

	printf("somma cifre del numero vale %d \n", sommaCifre(n));

	return 0;
	
}