#include <stdio.h>

int fibonacci(int n){
	
	int f0 = 0;
	int f1 = 1;

	if(n==0)
		return f0;
	else if(n==1)
		return f1;
	else{
		
		int fn = 0;
		
		for(int i=2; i<=n; i++){

			fn = f0 + f1;
			f0 = f1;
			f1 = fn;
			
	}
		return fn;
	}
	
}

int main(){

	int n;
	printf("inserisci la posizione di cui si vuole sapere il valore all'interno della succesione di Fibonacci: ");
	scanf("%d", &n);

	printf("f(n) vale %d \n", fibonacci(n));

	return 0;
}