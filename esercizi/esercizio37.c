#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int minimo(int* a, int dim){
    int m = *(a+0);
    for(int i=1; i<dim; i++){
        if(*(a+i) < m)
            m = *(a+i);
    }
    return m;
}

int massimo(int*a, int dim){
    int m = *(a+0);
    for(int i=1; i<dim; i++){
        if(*(a+i) > m)
            m = *(a+i);
    }
    return m;
}

void inizializzaZero(int* a, int dim){
    for(int i=0; i<dim; i++)
        *(a+i) = 0;
}
void countingSort(int* a, int dim){
    int min = minimo(a, dim);
    int mas = massimo(a, dim);    
    int k = abs(mas) + abs(min) + 1;
    int* mappa = (int*)malloc(sizeof(int)*k);
    inizializzaZero(mappa, k);
    for(int i=0; i<dim; i++)
        *(mappa + (*(a+i)-min)) += 1; 
    int c = 0;
    for(int i=0; i<k; i++){
        while(*(mappa+i)>0){
            *(a+c) = i+min;
            *(mappa+i) -= 1;
            c++;
        }
    }
}

int main(){

    int a [] = {-2, -3, -1,-5, -2, -1, -4, -5, -4, -1};
    countingSort(a, 10);
    for(int i=0; i<10; i++)
        printf("%d ",*(a+i));
    printf("\n");
    
    return 0;
}