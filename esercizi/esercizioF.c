#include <stdio.h>

double a(int n){

	if(n==1)
		return 0.5;
	return (a(n-1)+1)/2;
	
}

int main(){

	int n;
	scanf("%d", &n);

	printf("a(n) vale %lf \n", a(n));
	
	return 0;
}