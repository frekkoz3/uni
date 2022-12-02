#include <stdio.h>

int min(int a, int b){
	
	if(a<b)
		return a;
	return b;
	
}

int mas(int a, int b){
	
	if(a>b)
		return a;
	return b;
	
}

int is_inside(int x, int y, int z){

	if(x >= y && x <= z)
		return 0;
	return -1;
	
}

int overlap_size (int i, int j, int t, int u){
	//vado a generare l'intersezione sfruttando delle proprietà delle insiemistiche (abbiamo sicuramente un'interesezione perché j>=t)
	int a = min(i,t);
	int b = mas(i,t);
	int c = min(j,u);
	int d = mas(t,u);

	int contaElementi = 0;

	printf("[ ");
	for(int i=a; i<=d; i++){

		if(is_inside(i,b,c)==0){
			contaElementi++;
			printf("%d ", i);	
		}
		
	}
	printf("]\n");

	return contaElementi;
	
}

int main(){

	int i, j, t, u;

	scanf("%d", &i);
	scanf("%d", &j);
	scanf("%d", &t);
	scanf("%d", &u);

	printf("[%d, %d] intersecato [%d, %d] \n", i, j, t, u);
	int dim = overlap_size(i,j,t,u);
	printf("numero elementi: %d \n", dim);
	return 0;
}