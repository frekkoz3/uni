#include <stdio.h>

int s1(int n){

	if(n == 1)
		return 1;

	return n + s1(n-1);
	
}

int s2(int a, int b){
	
	int s = 0;

	for(int i=a; i<=b; i++)
		s += s1(i);

	return s;
	
}

int main(){

	int a;
	int b;
	printf("inserisci a: ");
	scanf("%d", &a);
	printf("inserisci b: ");
	scanf("%d", &b);

	printf("la sommatoria da a a b vale %d \n", s2(a, b));
	
	return 0;
	
}