#include <stdio.h>
#include <stdlib.h>
void stampaArray(int* a, int dim){
    for(int i=0; i<dim; i++)
        printf("%d ", *(a+i));
    printf("\n");
}
int* merge(int* a, int dimA, int*b, int dimB){
    int dimC = dimA+dimB;
    int* c = (int*)malloc(sizeof(int)*dimC);
    int contaA = 0;
    int contaB = 0;
    for(int i=0; i<dimC; i++){
        if (contaA < dimA && contaB < dimB){
            if(*(a+contaA) < *(b+contaB)){
                *(c+i) = *(a+contaA);
                contaA++;
            }else{
                *(c+i) = *(b+contaB);
                contaB++;
            } 
        }else if(contaA >= dimA){
            *(c+i) = *(b+contaB);
            contaB++;
        }else{
             *(c+i) = *(a+contaA);
                contaA++;
        }
    }
    
    return c;
}

int main(){

    int a[] = {1, 2, 5, 7, 9};
    int b[] = {3, 4, 6, 8, 10};

    stampaArray(merge(a, 5, b, 5), 10);   

    return 0;
}