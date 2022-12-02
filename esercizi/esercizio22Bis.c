#include <stdio.h>
#include <stdlib.h>

int sommaPari(int a[], int dim, int i){

    if(i == dim-1 && a[i]%2 == 0)
        return a[i];
    if(i == dim-1 && a[i]%2 != 0)
        return 0;
    if(a[i]%2==0)
        return a[i] + sommaPari(a, dim, i+1);
    else
        return 0 + sommaPari(a, dim, i+1);
    
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int dim = 10;
    
    int a[dim];

    for(int i=0; i<dim; i++)
        a[i] = (rand() % 10);    //RANDOM TRA 0 E 49

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    printf("somma dei pari vale %d \n", sommaPari(a,dim,0));
    
    return 0;
}