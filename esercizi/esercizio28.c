#include <stdio.h>
#include <stdlib.h>

int sommaTriangolareK(int a[], int dim, int k){

    int i = 2;
    int found = 0;

    while(i < dim && found==0){
        if(a[i] + a[i-1] + a[i-2] == k)
            found =1;
        i++;
    }

    return found;    
}

int main(){

    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int n = 10;
    int k = 5;

    int a[n];

    for(int i=0; i<n; i++)
        a[i] = (rand() % 5) +1;    

    for(int i=0; i<n; i++)
        printf("%d \n", a[i]);

    printf("\n");

    if(sommaTriangolareK(a,n,k) == 1)
        printf("esistono 3 numeri successivi la cui somma fa k \n");
    else
        printf("non esistono 3 numeri succesivi la cui somma fa k \n");

    return 0;
}