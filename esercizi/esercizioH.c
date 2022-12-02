#include <stdio.h>
#include <math.h>

double s(double n){

	double somma = 0;

	for(int i=0; i<=n; i++){

		double parameter = (1 / pow((2*i+1),2));
		somma += parameter;
		printf("s_%d = %lf \n", i, parameter);
		
	}

	return somma;
	
}

int main(){

	double n;
	scanf("%lf", &n);
	printf("la sommatoria da 0 ad n vale %lf", s(n));

	return 0;
} 