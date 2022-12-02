#include <stdio.h>

double s(double n){

	if(n==0)
		return 1;

	double f = ((2*n+1)*(2*n+1));
	
	return (1/f + s(n-1));
	
}

int main(){

	for(double i=0; i<10; i++){
		printf("la sommatoria da 0 ad %lf vale %fl \n", i, s(i));
	}

	return 0;
}