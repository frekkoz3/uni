#include <stdio.h>

int min(int a, int b){

	if(a<b)
		return a;
	return b;
	
}

int minATre(int a, int b, int c){

	return min(min(a,b),min(b,c));
	
}

int mas(int a, int b){
	
	if(a>b)
		return a;
	return b;
	
}

void test(int a, int b){

	int sup = mas(a,b);

	for(int i=1; i<=sup; i++){

		printf("tripletta %d %d %d : minimo vale %d \n", a, b, i, minATre(i,a,b));
		
	}
	
}

int main(){

	int a;
	int b;
	int c;

	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);

	printf("il minore tra i tre numeri è %d \n", minATre(a,b,c));

	scanf("%d",&a);
	scanf("%d",&b);

	test(a,b);
	
	return 0;
}