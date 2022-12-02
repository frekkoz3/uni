#include <stdio.h>

void somma_armonica (int n, double* h){

    if (n==1)    //così facendo non serve che h sia inizializzata a 0 perché ogni volta per prima cosa inizializza a 1 cioè il caso di n==1
        *h = 1.0; 
    else{
        somma_armonica(n-1, h);
        *h = (1.0 / n) + *h;    //per mantenere la divisione tra double             dobbiamo mettere 1.0
        
    }
    
}

int main(){

    double h;
    int n;

    printf("inserisci n: ");
    scanf("%d", &n);

    somma_armonica(n, &h);
    
    printf("somma armonica di %d vale : %lf \n", n, h);
    
}