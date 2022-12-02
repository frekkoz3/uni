#include <stdio.h>

void inizializzaFalse(int* a, int dim){
    for(int i=0; i<dim; i++)
        *(a+i) = 0;
}

int contaSingoli(int* a, int dim){
    int *trovati = (int*)malloc(sizeof(int)*dim);
    int contaDoppi = 0;
    inizializzaFalse(trovati, dim);
    for(int i=0; i<dim; i++){
        for(int j=i+1; j<dim; j++){
            if(*(trovati+j) == 0 && *(a+i) == *(a+j)){
                *(trovati+j) = 1;
                contaDoppi ++;
            }
        }
    }
    return dim - contaDoppi;
}

void stampaArray(int* a, int dim){
    for(int i=0; i<dim; i++)
        printf("%d", *(a+i));
}

int* arraySenzaDoppioni(int* a, int dim){

    int *trovati = (int*)malloc(sizeof(int)*dim);
    inizializzaFalse(trovati, dim);
    
    int dimB = contaSingoli(a, dim);
    int *b = (int*)malloc(sizeof(int)*dimB);
    int contaB = 0;
    
    for(int i=0; i<dim; i++){
        for(int j=i+1; j<dim; j++){
            if(*(trovati+j) == 0 && *(a+i) == *(a+j)){
                *(trovati+j) = 1;
            }
        }
    }
    for(int i=0; i<dim; i++){
        if(*(trovati+i) == 0){
            *(b+contaB) = *(a+i);
            contaB++;
        }
    }
    return b;
}

int main(){

    int a[] = {1, 1, 2, 3, 4, 4, 5, 6};
    int dimB = contaSingoli(a, 8);
    stampaArray(arraySenzaDoppioni(a,8), dimB);
    
    return 0;
}