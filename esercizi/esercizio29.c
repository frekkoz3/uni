#include <stdio.h>
#include <stdlib.h>

void elementiMultipli(int a[], int b[], int dim){

    int indiceB = 0;
    //inizializzo a 0 tutti i valori di B così poi leggo solo quelli diversi da 0
    for(int i=0; i<dim;i++)
        b[i] = 0;

    for(int i=0; i<dim; i++){

        int j=0;
        int found = 1;
        
        while(found == 1 && j < dim){
            if(i==j)
                j++;
            else if(a[j]%a[i] == 0){
                found = 0;
                printf("%d è multiplo di %d \n", a[i], a[j]);                
            }                
            else 
                j++;            
        }
        if(found == 1){
            b[indiceB] = a[i];
            indiceB++;
        }
    }

}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int dim = 10;
    
    int a[dim];
    int b[dim];

    for(int i=0; i<dim; i++)
        a[i] = (rand() % 50) +1;    //RANDOM TRA 1 E 50

    for(int i=0; i<dim; i++)
        printf("%d \n", a[i]);

    elementiMultipli(a, b, dim);

    printf("\n");
    
    for(int i=0; i<dim; i++){
        if(b[i]!=0)
            printf("%d \n", b[i]);
    }

    return 0;
}