#include <stdio.h>

int sRic(int a){	//SUCCESSIONE IN FORMA RICORSIVA

	if(a==0)
		return 1;
	return (2 * sRic(a-1) + 3);
	
}

int sIte(int a){

	int s = 1;	//QUESTO E' IL CASO BASE DI 0
	
	for(int i=1; i<=a; i++){
		s*=2;
		s+=3;
	}
		
	return s;
	
}

int qIte(int z, int t){

	int x = 0;
	
	for(int i=z; i<=t; i++)
		x += (sRic(i));

	x*=3; //VISTO CHE E' UNA COSTANTE LA TIRO FUORI
	
	return x;
	
}

int qRic(int z, int t){	//E' LA VERSIONE PIU' INNATURALE DEL PROBLEMA
	
	if(z==t)	
		return 3*sRic(z);		//SE IL CASO BASE E' SULLA Z, LA Z DEVE MODIFICARSI. VICEVERSA SI USA LA T
	return 3*sRic(z) + qRic(z+1, t);
	
}

int main(){

	int z;
	printf("inserisci z: ");
	scanf("%d", &z);

	int t;
	printf("inserisci t: ");
	scanf("%d", &t);
	
	printf("la sommatoria vale %d \n", qIte(z,t));
	printf("la sommatoria vale %d \n", qRic(z,t));
	
	return 0;
}