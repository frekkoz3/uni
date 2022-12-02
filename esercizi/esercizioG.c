#include <stdio.h>

double a(double n, double p){	 //SE VOGLIO VISUALIZZARE LA SERIE DEVO USARE UN PROGRAMMA ITERATIVO DAL BASSO VERSO L'ALTO CON UN FOR E NON UNA MANIERA RICORSIVA!

	if(n==1)
		return p;
	return 0.5*(a(n-1,p)+p/a(n-1,p));
	
}

int main(){

	double n;
	double p;
	scanf("%lf", &n);
	scanf("%lf", &p);
	printf("il valore di a(n,p) è %lf \n", a(n,p));
	
	return 0;
}