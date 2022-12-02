#include <stdio.h>
#include <math.h>

int isPrimo(int n){

	if(n==2 || n==1)
		return 1;

	if(n%2==0)
		return 0;

	int i = 3;
	
	while (i <= sqrt(n))
		{
			if(n%i==0)
				return 0;
			i+=2;
		}

	return 1;
	
}

void test (){

	for(int i=1; i<=100; i++){

		if(isPrimo(i))
			printf("%d è primo \n",i);
		else
			printf("%d non è primo \n", i);
		
	}
	
}

int main(){

	int n; 
	printf("inserisci numero: ");
	scanf("%d", &n);

	if(isPrimo(n))
		printf("il numero è primo \n");
	else
		printf("il numero non è primo \n");

	test();
	
	return 0;
}