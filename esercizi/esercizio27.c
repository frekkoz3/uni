#include <stdio.h>
#include <stdlib.h>

int kEsimoElementoMinore(int a[], int dim, int k){

    int min = 0;
    
    for(int i=0; i<k; i++){
        min = a[i];
        int posM = i;
        for(int j=i+1; j<dim; j++){
            if(a[j]<min){
                min = a[j];
                posM = j;
            }                
        }
        int t = a[i];
        a[i] = a[posM];
        a[posM] = t;
    }
    return min; //ESEGUO UN BUBBLE SORT K VOLTE
    
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int n = 10;
    int k = 5;

    int a[n];

    for(int i=0; i<n; i++)
        a[i] = (rand() % 20) +1;    

    for(int i=0; i<n; i++)
        printf("%d \n", a[i]);

    printf("\n");

    printf("elemento k-esimo minore è %d \n", kEsimoElementoMinore(a,n,k));

    return 0;
}