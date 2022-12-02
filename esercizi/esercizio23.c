#include <stdio.h>
#include <stdlib.h>

int doppioni(int a[], int dim){

    int i = 0;
    int j = 1;
    int doppio = 0;    //SETTO A 0 COME NON AVER TROVATO

    while(i < dim && doppio == 0)
    {
        j = i+1;
        while(j<dim && doppio == 0){
            if(a[i] == a[j]){
                doppio = 1;
                printf("%d in pos %d è uguale a %d in pos %d \n", a[i], i, a[j], j);
            } 
            j++;
        }
        i++;
    }
    
    return doppio; //SE HO TROVATO UN DOPPIONE RESTITUISCO VERO
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int dim = 10;
    
    int a[dim];

    for(int i=0; i<dim; i++)
        a[i] = (rand() % 50);    

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    if(doppioni(a, dim) == 1)
        printf("sono presenti doppioni \n");
    else
        printf("non sono presenti doppioni \n");
    
    return 0;
}