#include <stdio.h>
#include <stdlib.h>

//NOTA BENE CHE QUESTO PROGRAMMA ASSUME CHE NON CI SIANO DOPPIONI

int tuttiDiversi(int a[], int dim){

    for(int i=0; i<dim; i++){
        for(int j=i+1; j<dim; j++){
            if(a[i] == a[j])
                return 0;   
            //0 SIGNIFICA CHE HO DUE VALORI UGUALI
        }   
    }
    return 1;    
}

int kEsimoMinore(int a[], int dim, int k){

    //LE VARIABILI DI CUI AVREMO BISOGNO SARANNO K E K' 
    //DOVE K INDICA L'INDICE DEL PIVOT FISSATO E
    //K' INDICA DOVE FINISCE IL PIVOT UNA VOLTA CREATE
    //LE PARTIZIONI

    //INF E SUP SARANNO GLI ESTREMI ENTRO CUI
    //OCCORRERA' 
    //ITERARE L'ARRAY PER EVITARE DI COMPIERE CALCOLI
    //INUTILI

    //CI PERMETTERANO SEMPRE OLTRETUTTO DI CALCOLARE
    //LA DIMENSIONE MASSIMA CHE POTRA' AVERE 
    //OGNI SINGOLA PARTIZIONE (DIM = SUP - MIN)

    int kPrimo = 0;
    int inf = 0;
    int sup = dim-1;

    //PER POTER GESTIRE LE DUE PARTIZIONI
    //SENZA CARICARLE DI VALORI PARTICOLARI
    //CHE POTREBBE IN CASI PARTICOLARI 
    //GENERARMI ERRORE
    //CONTO OGNI VOLTA QUANTI MINORI CI SONO 
    //E QUANTI MAGGIORI 
    
    int contaMinori = 0;
    int contaMaggiori = 0;
    
    do{
        //USERO' UN PIVOT ANZICHE' RICHIAMARE SEMPRE 
        //A[K]
        int pivot = a[k];
        int dim = sup - inf; 
        int minori [dim];
        int maggiori [dim];

        //CREO LE DUE PARTIZIONI MAGGIORI E MINORI
        
        for(int i = inf; i<= sup; i++){
            if(i == k)
                continue;
            else{
                if(a[i] < pivot){
                    minori[contaMinori] = a[i];
                    contaMinori++;
                }else{ 
                    maggiori[contaMaggiori] = a[i];
                    contaMaggiori++;
                }       
            }
        }

        //RICOMPONGO L'ARRAY E TROVO K'

        for(int i=0; i<contaMinori; i++)
            a[inf+i] = minori[i];

        kPrimo = inf+contaMinori;

        a[kPrimo] = pivot;

        for(int i=0; i<contaMaggiori; i++)
            a[kPrimo+1+i] = maggiori[i];

        //ORA RIASSEGNO I VALORI DI INF E SUP

        if(k == kPrimo)
            continue;
        else if(kPrimo < k)
            inf = (kPrimo + 1);
        else
            sup = (kPrimo - 1);

        //DOBBIAMO RIAZZERARE QUESTE VARIABILI
        //AD OGNI CICLO
        contaMinori = 0;
        contaMaggiori = 0;
        
    }while(a[k] != a[kPrimo]);

    return a[k];

}
int kEsimoMaggiore(int a[], int dim, int k);


int main(){

    //SETTO IL SEME DEL RANDOM
    
    time_t t;
    srand((unsigned)time(&t));

    //N E' LA DIMENSIONE DELLA LISTA, K L'INDICE K-ESIMO
    
    int n = 8;
    int k = 3;

    int a[n];

    do{
    for(int i=0; i<n; i++)
        a[i] = (rand() % 10) +1;    
    }while(tuttiDiversi(a, n) == 0);

    for(int i=0; i<n; i++)
        printf("%d  ", a[i]);
    printf("\n");

    printf("k-esimo elemento (k uguale a %d) più piccolo vale %d \n", k+1, kEsimoMinore(a,n,k));


    return 0;
}