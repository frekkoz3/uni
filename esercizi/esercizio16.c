#include <stdio.h>

int main(){

	int dim=0;
	scanf("%d", &dim);

	int a[dim];

	for(int i=0; i<dim; i++)
	{
		a[i] = i;
		printf("%d \n", a[i]);
	}

	return 0;
}