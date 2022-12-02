#include <stdio.h>

int main(){

	int a[5] = {1, 3, 0, -2, 7};
	
	for(int i=0; i<5; i++){

		if(a[i]%2 == 0)
			a[i] = 0;
		else
			a[i] = 1;
		
	}
	
	for(int i=0; i<5; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}