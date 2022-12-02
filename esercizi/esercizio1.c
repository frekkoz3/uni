#include <stdio.h>

int main()
{

	float x;

	printf("inserire un valore: ");
	scanf("%f", &x); //IMPORTANTE L'&

	if(x<0)
		printf("valore assoluto vale: %f", -x);
	else
		printf("valore assoluto vale: %f", x);

	return 0;
}