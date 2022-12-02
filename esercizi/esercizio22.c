#include <stdio.h>
#include <stdlib.h>

int sommaPari(int a[], int dim){

    int somma = 0;

    for(int i=0; i<dim; i++){

        if(a[i]%2==0)
            somma += a[i];
        
    }

    return somma;
    
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int dim = 10;
    
    int a[dim];

    for(int i=0; i<dim; i++)
        a[i] = (rand() % 50);    //RANDOM TRA 0 E 49

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    printf("somma dei pari vale %d \n", sommaPari(a,dim));
    
    return 0;
}