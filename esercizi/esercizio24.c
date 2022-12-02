#include <stdio.h>
#include <stdlib.h>

int prodottoScalare(int a[], int b[], int dim){
    int p = 1;

    for(int i=0; i<dim; i++)
        p *= (a[i] * b[i]);

    return p;    
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int dim = 3;
    
    int a[dim];
    int b[dim];

    for(int i=0; i<dim; i++)
        a[i] = (rand() % 5) +1;    

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    printf("\n");
    
    for(int i=0; i<dim; i++)
        b[i] = (rand() % 5)+1;    

    for(int i=0; i<dim; i++)
        printf("%d \n", b[i]);

     printf("\n");

    printf("prodotto scalare vale %d \n", prodottoScalare(a,b,dim));
    
    return 0;
}