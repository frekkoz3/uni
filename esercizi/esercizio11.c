#include <stdio.h>

int main(){

	double a0 = 1;
	double a1 = 2;

	int n;

	printf("inserisci n: ");
	scanf("%d", &n);

	double an = 0;

	for(int i=2; i<= n; i++){

		if( i%2 == 0){
			an = ((i+3*(a0-2))/a1);
			a0 = a1;
			a1 = an;
		}else{
			an = ((i+3*(a1-2))/a0);
			a0 = a1;
			a1 = an;
		}

	}
	
	if(n==0)
		printf("a(n) vale 1\n");
	else if(n==1)
		printf("a(n) vale 2\n");
	else 
		printf("a(n) vale %lf\n", an);
	
	return 0;
}