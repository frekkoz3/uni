#include <stdio.h>

double minimo(double a, double b){

	if(a<b)
		return a;
	return b;
	
}

double massimo(double a, double b){

	if(a>b)
		return a;
	return b;
}

double valoreAssoluto(double a, double b){

	return massimo(a,b) - minimo(a,b);
	
}

int ugualiAMenoDiEpsilon(double a, double b){

	double e = 0.000000001;
	return(valoreAssoluto(a,b)<e);
	
}

int main(){

	double a;
	double b;
	
	scanf("%lf",&a);
	scanf("%lf",&b);

	if(ugualiAMenoDiEpsilon(a,b))
		printf("%lf e %lf sono uguali a meno di 10^-9 \n", a, b);
	else
		printf("%lf e %lf non sono uguali a meno di 10^-9 \n", a, b);

	return 0;
}