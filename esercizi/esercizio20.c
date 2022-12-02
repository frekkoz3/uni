#include <stdio.h>

// CALCOLATORE DI VARIANZA

double mediaArray (int a[], int dim){

    double somma = 0;

    for(int i=0; i<dim; i++)
        somma += a[i];

    double dime = 1.0 * dim;
    
    return somma/dime;
    
}

double sommatoriaVarianzaQuadra (int a[] , int dim){

    double media = mediaArray (a, dim);

    double somma = 0;

    for(int i=0; i<dim; i++)
        somma += ((a[i] - media)*(a[i] - media));

    return somma;
    
}

double varianza (int a[] , int dim){

    double dime = 1.0 * dim;

    return sommatoriaVarianzaQuadra(a, dim) / dime;
    
}

int main(){

    int a[10];

    for(int i=0; i<10; i++)
        scanf("%d", &a[i]);

    printf("la media aritmetica vale %lf \n", mediaArray(a, 10));
    printf("la varianza vale %lf \n", varianza(a, 10));
    
    return 0;
}