#include <stdio.h>
#include <math.h>

double s(double n, int k){
	
	double somma = 0;

	for(int i = 0; i <= n; i++){

		double parameter = ((i * pow(k, i+1)) / pow(3, i));
		somma += parameter;
		printf("s_%d = %lf \n", i, parameter);
		
	}

	return somma;
	
} 

void test (double n){

	for(int i = 0; i<100; i++){

		printf("serie con n pari a %lf e k pari a %d vale %lf \n", n, i, s(n,i));
		
	}
	
}
void testMultipliDi3(double n){

	for(int i = 3; i < 50; i+=3)
		{

			for(double j = n; j < (n+10); j++){
					printf("serie con n pari a %d e k pari a %d vale %lf \n", (int)j, i, s(j,i));
			}
			
	}
	
}

int main(){

	double n;
	scanf("%lf", &n);
	double s3 = s(1000,4);
	//test(n);
	//testMultipliDi3(n);
	return 0;
}