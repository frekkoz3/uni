#include <stdio.h>
#include <stdlib.h>

//questa è la mia struttura nodo
struct node{

    int val;
    struct node* nxt;
    
};

//la chiamo node_t
typedef struct node node_t;

//ESERCIZIO 1

//notare bene che è una funzione che 
//restituisce un node_t*
node_t* makelist(){

    //questa è la mia testa
    //quella che in ogni caso ritornerò
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head -> nxt = NULL;
    //questo invece è il nodo che userò
    //per iterare e inserire nuovi elementi 
    //nella lista
    node_t* next = (node_t*)malloc(sizeof(node_t));
    next -> nxt = NULL;

    //ricordiamoci che l'inserimento termina con n == -1
    int n = 0;

    while(n != -1){

        printf("inserisci valore: ");
        scanf("%d", &n);
        if(n == -1){//caso di uscita
            continue;            
        }else if(head -> nxt == NULL){//primo inserimento
            head -> val = n;
            head -> nxt = next;
            next = head;
        }else{//tutti i seguenti inserimenti
            next -> nxt = (node_t*)malloc(sizeof(node_t));
            next -> nxt -> val = n;
            next -> nxt -> nxt = NULL;
            next = next -> nxt;
        }
        
    }

    return head;    
}

//funzione che restituisce la dimensione 
//di una lista
int lenlist(node_t* list){

    node_t* current = list;
    int c = 0;

    while(current != NULL){
        current = current -> nxt;
        c++;
    }

    return c;
}

//questa è una funzione che restituisce
//una lista *UGUALE* in valori ma 
//differente in indirizzi rispetto ad 
//una lista passata come argomento

//ci può essere utile se vogliamo 
//usare e modificare i valori di una lista
//mantenendo però la lista originale intatta
node_t* copylist(node_t* list){

    node_t* copyhead = (node_t*)malloc(sizeof(node_t));
    copyhead -> nxt = NULL;
    node_t* copynext = (node_t*)malloc(sizeof(node_t));
    copynext -> nxt = NULL;

    while(list != NULL){
        if(copyhead -> nxt == NULL){
            copyhead -> val = list -> val;
            copyhead -> nxt = copynext;
            copynext = copyhead;
            list = list -> nxt;
        }else{
            copynext -> nxt = (node_t*)malloc(sizeof(node_t));
            copynext -> nxt -> val = list -> val;
            copynext -> nxt -> nxt = NULL;
            copynext = copynext -> nxt;
            list = list -> nxt;
        }
        
    }
    
    return copyhead;
}

//funzione che restituisce una copia
//fino alla posizione k-esima (inclusa)
node_t* copylistuntilk(node_t* list, int k){

    if(k > lenlist(list))
        return copylist(list);
    
    node_t* copyhead = (node_t*)malloc(sizeof(node_t));
    copyhead -> nxt = NULL;
    node_t* copynext = (node_t*)malloc(sizeof(node_t));
    copynext -> nxt = NULL;
    int contatore = 0;

    while(contatore < k){
        if(copyhead -> nxt == NULL){
            copyhead -> val = list -> val;
            copyhead -> nxt = copynext;
            copynext = copyhead;
            list = list -> nxt;
        }else{
            copynext -> nxt = (node_t*)malloc(sizeof(node_t));
            copynext -> nxt -> val = list -> val;
            copynext -> nxt -> nxt = NULL;
            copynext = copynext -> nxt;
            list = list -> nxt;
        }
        contatore++;
        
    }
    
    return copyhead;
}

//funzione che restituisce una copia dalla 
//posizione k-esima (esclusa)
node_t* copylistfromk(node_t* list, int k){

    if(k > lenlist(list))
        return NULL;
    
    int contatore = 1;
    while(contatore <= k){
        list = list -> nxt;
        contatore++;
    }
    
    return copylist(list);
}
//ESERCIZIO 2

//funzione che stampa una lista
void printlist(node_t* list){

    node_t* current = list;

    while(current != NULL){
        printf("%d ", current -> val);
        current = current -> nxt;
    }
    printf("\n");
    
}

//ESERCIZIO 3 e 3BIS

//funzione che restituisce una lista nuova
//contenente il push di una listaA 
//in coda ad una listaB

//uso delle copie
//per evitare di alterare la struttura delle liste
//passate come parametri

//pusho la listaA in coda alla listaB
node_t* pushlist(node_t* listA, node_t* listB){

    //se la listaB è vuota
    //restituisce una copia della listaA
    if(listB == NULL)
        return copylist(listA);

    //la testa la abbino
    //ad una copia della listaB
    node_t* head = copylist(listB);
    node_t* current = head;
    
    //operazione con cui mi porto alla coda
    //alla copia della listaB
    while(current-> nxt != NULL)
        current = current -> nxt;

    //pusho in coda alla copia della listaB
    //la copia della lista A
    current -> nxt = copylist(listA);

    return head;
}

//funzione che inserisce una lista b 
//ad un certo punto di una lista a
node_t* insertlist(node_t* listA, node_t* listB){

    node_t* copyA = copylist(listA);
    node_t* copyB = copylist(listB);
    node_t* temporarylist = copyA -> nxt;
    copyA -> nxt = copyB;
    while(copyB -> nxt != NULL)
        copyB = copyB -> nxt;
    copyB -> nxt = temporarylist;

    return copyA;

}

//funzione specifica dell'esercizio 3
node_t* specialmerge(node_t* listA, node_t* listB, int j){

    node_t* listC = NULL;
    int len = lenlist(listA);

    if(j <= 0){
        listC = pushlist(listB, listC);
        listC = pushlist(listA, listC);
    }else if(j >= len){
        listC = pushlist(listA, listC);
        listC = pushlist(listB, listC);
    }else{
        node_t* untilj = copylistuntilk(listA, j);
        node_t* fromj = copylistfromk(listA, j);
        node_t* firstpart = pushlist(listB, untilj);
        listC = pushlist(fromj, firstpart);
    }
        
    return listC;
}

//ESERCIZIO 5

//funzione che mi libera l'heap 
//da un'intera lista 
//nota bene: usare free(list) libera l'heap
//solo da un elemento della lista 

//poichè vogliamo lavorare proprio sulla lista 
//che passiamo come argomento, dobbiamo usare
//un doppio puntatore (cosa evitabile se 
//si definisce in precedenza typedef 
//node_t* list)

//ne deriva dunque tutta la logica 
//delle operazioni tra puntatori
void freelist(node_t** list){
    
    while(*list != NULL){//usiamo un nodo di appoggio, spostiamo la lista
                         //a nxt e liberiamo il nodo di appoggio
        node_t* f = *list;
        *list = (*list) -> nxt;
        free (f);
    }
    
}

//funzione che libera l'heap di 
//k elementi da una lista 

//ps: se k > numero elementi della lista
//la libera tutta di default
void freelistuntilk(node_t** list, int k){

    if (k >= lenlist(*list))
        freelist(list);
    else{
        while(k > 0){
        node_t* f = *list;
        *list = (*list) -> nxt;
        free (f);
        k--;
        }
    } 
    
}

//ESERCIZIO 4

//funzione che aggiunge in testa ad una lista un elemento
void pushdown(node_t** list, int n){
    
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node -> val = n;
    new_node -> nxt = *list;
    *list = new_node;
    
}

//funzione che cerca quanti elementi sono minori
//di un dato k all'interno di una lista ordinata
int findk(node_t* list, int k){

    node_t* current = list;
    int contatore = 0;

    while(current != NULL && k > current -> val){
        contatore ++;
        current = current -> nxt;
    }

    return contatore;
}

//funzione specifica per l'esercizio 4
void specialinsert(node_t** list, int k){
    
    freelistuntilk(list, findk(*list, k));
    pushdown(list, k);
    
}

//ESERCIZIO 6

//funzione che rimuove l'elemento successivo ad un determinato 
//elemento in una lista
void removenext(node_t** list){

    node_t* temporary_node = (*list) -> nxt;
    (*list) -> nxt = temporary_node -> nxt;
    free(temporary_node);
    
}

//funzione che elimina gli elementi duplicati da una lista
void cleanupduplicates(node_t** list){

    node_t* el1 = *list;
    
    while(el1 != NULL){
        node_t* el2 = el1;
        while(el2 -> nxt != NULL){
            if(el1 -> val == el2 -> nxt -> val){
                removenext(&el2);
            }else
                el2 = el2 -> nxt;
        }
        el1 = el1 -> nxt;
    }
    
}

//ESERCIZIO 7

//funzione che swappa due nodi (i valori)
//(e penseranno "che fottuto figlio di puttana")
void swapnodes(node_t** nodeA, node_t** nodeB){
    
    int t = (*nodeA) -> val;
    (*nodeA) -> val = (*nodeB) -> val;
    (*nodeB) -> val = t;
    
}

//funzione che inverte una lista
void invertlist(node_t** list){

    int len = lenlist(*list);
    node_t* head = *list;

    //current è di fatto l'elemento che 
    //scorre verso l'alto
    node_t* current = head;

    //il contatoreup è la variabile che mi indica 
    //a quale elemento sono arrivato dal basso verso l'alto
    int contatoreup = 0;

    //il contatore down è la variabile che mi indica
    //a quale elemento sono arrivato dall'alto verso il basso
    int contatoredown = len-1;
    
    while(contatoreup < contatoredown){
        //notare bene che la coda parte sempre
        //dalla testa
        node_t* tail = head;
        while(contatoredown > 0){
            tail = tail -> nxt;
            contatoredown--;
        }
        swapnodes(&current, &tail);
        contatoreup++;
        contatoredown = len - contatoreup - 1;
        current = current -> nxt;
    }

}
int main(){

    node_t* listA = makelist();
    node_t* listB = makelist();
    printlist(listA);
    printlist(listB);
    node_t* listC = specialmerge(listA, listB, 3);
    printlist(listC);
    
    return 0;
}