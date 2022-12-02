#include <stdlib.h>
#include <stdio.h>

int main(){

    //MEMORIA DINAMICA
    
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);
    
    //(INT*) = CASTING TO INT*
    //MALLOC = MEMORY ALLOC
    //MALLOC RESTITUISCE UN VOID*
    //VOID* E' UN PUNTATORE DI TIPO UNIVERSALE
    //SIZEOF(INT) = DIMENSIONE DI UN INTERO
    //N = NUMERO INSERITO DA UTENTE
    //LA MEMORIA DINAMICA SI TROVA NELL'HEAP 
    //A DIFFERENZA DELLA MEMORIA STATICA
    //CHE SI TROVA NELLA MEMORIA INTERNA
    //L'HEAP NON HA I FRAME

    free(a);
    
    //L'HEAP BISOGNA GESTIRSELO DA SE
    //DUNQUE BISOGNA LIBERARE LA MEMORIA 
    //UNA VOLTA CHE ABBIAMO CONCLUSO DI USARE
    //UN DETERMINATO SPAZIO

    printf("%p", a);

    int x = 10;
    int *p;
    {
        int y=12;
        p = (int*)malloc(sizeof(int));
        *p = y + 1;       
    }
    x = *p;
    
    //TUTTO VALIDO PERCHE' L'HEAP ESISTE ANCHE
    //AL DI FUORI DELLE PARENTESI

    //FUN FACT
    //IN JAVA IL NEW FA L'EQUIVALENTE DEL MALLOC
    //ERGO: ALLOCA NELL'HEAP UN OGGETTO
    
    return 0;
}