#include <stdio.h>
#include <stdlib.h>

int bContieneElementiA(int a[], int n, int b[], int m){

    int i=0; 
    int j=0;
    int found = 0; //0 STA A FALSO

    while(i < n && found == 0){
        j=0;
        while(j<m && found == 0)
        {
                if(a[i] == b[j])
                    found = 1;
                j++;
        }
        i++;        
    }

    return found; //SE VALE 1 ALLORA E' CONTENUTO
    
}

int main(){
    time_t t;
    srand((unsigned)time(&t));    //SETTO IL SEME DEL RANDOM
    
    int n = 5;
    int m = 8;

    int a[n];
    int b[m];

    for(int i=0; i<n; i++)
        a[i] = (rand() % 50) +1;    

    for(int i=0; i<n; i++)
        printf("%d \n", a[i]);

    printf("\n");
    
    for(int i=0; i<m; i++)
        b[i] = (rand() % 50)+1;    

    for(int i=0; i<m; i++)
        printf("%d \n", b[i]);

     printf("\n");

    if(bContieneElementiA(a, n, b, m)==1)
        printf("B CONTIENE ALMENO UN ELEMENTO DI A\n");
    else
        printf("B NON CONTIENE NEMMENO UN ELEMENTO DI A\n");

    return 0;
}