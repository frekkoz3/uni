#include <stdio.h>

void caricaNNumeriTriangolari(int a[], int dim){

    int s = 0;
    a[0] = 1;
    
    for(int i=2; i<=dim; i++){
        a[i-1] = a[i-2] + i;
    }
    
}

int main(){
    
    int dim = 10; //ASSUMIAMO DIM > 1

    int a[dim];

    caricaNNumeriTriangolari(a, dim);

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    return 0;
}