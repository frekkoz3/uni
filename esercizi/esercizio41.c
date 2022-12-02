#include <stdio.h>
#include <stdlib.h>

//LEZIONE SULLE LISTE

//STRUTTURA DEI NODI 

struct node{

    int val;
    struct node* nxt;

};

//DEFINSICO UN NODO COME ELEMENT

typedef struct node node_t;

//DEFINISCO UN PUNTATORE AD UN NODO COME LIST

typedef struct node* List;

int main(){

    //INIZIALIZZO IL NODO DI TESTA
    //USO ANZICHE' LISTA NODE_T* PER COMODITA' DI LETTURA

    node_t * head = NULL;
    head = (node_t *)malloc(sizeof(node_t));

    if(head == NULL)
        return 1;

    head -> val = 1;
    head -> next = NULL;

    //AGGIUNGO MANUALMENTE UN SECONDO NODO

    head -> next = (node_t *)malloc(sizeof(node_t));
    head -> next -> next = NULL;
    head -> next -> val = 2;

    //ITERO UNA LISTA

    note_t * current = head;

    while(current != NULL){
        print("%d\n", current->val);
        current = current -> next;
    }

    //AGGIUNGO UN ELEMENTO IN CODA ALLA LISTA

    //QUESTO E' IL PUSH_UP

    current = head;

    while(current != NULL)
        current = current -> next;

    current -> next = (node_t*)malloc(sizeof(node_t));
    current -> next -> next = NULL;
    current -> next -> val = 3;

    //AGGIUNGO N ELEMENTI AD UNA LISTA

    int n = 10;

    current = head; 

    //con questa operazione mi porto alla coda
    
    while(current -> next != NULL)
        current = current -> next;

    //qua inserisco gli n elementi in coda
    
    for(int i=0; i<n; i++){

        current -> next = (node_t*)malloc(sizeof(node_t));
        current -> next -> val = i + 3;
        current = current -> next;
        
    }

    //mi ricordo di assegnare NULL al next dell'ultimo valore
    
    current -> next = NULL;

    //AGGIUNGO UN ELEMENTO IN TESTA ALLA LISTA

    //QUESTO E' IL PUSH_DOWN

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node -> val = 0;
    new_node -> next = *head;
    *head = new_node;

    //RIMUOVO IL PRIMO ELEMENTO DALLA TESTA DELLA LISTA

    //QUESTO E' IL POP

    node_t* next_node = NULL;
    next_node -> next = (*head) -> next;
    free(*head);
    *head = next_node;

    //RIMUOVO L'ULTIMO ELEMENTO DELLA CODA DELLA LISTA

    //QUESTO E' IL REMOVE

    current = head; 

    //con questa operazione mi porto alla coda

    while(current -> next -> next != NULL)
        current = current -> next;

    //con questa operazione elimino l'elemento 
    
    free(current -> next);
    current -> next = NULL;

    //RIMUOVO UNO SPECIFICO ELEMENTO

    //QUESTO E' IL REMOVE_BY_INDEX

    int index = 3;

    current = head;

    //con questa operazione mi porto all'indice desiderato -1

    for(int i=0; i<index-1; i++)
        current = current -> next;

    node_t * temp_node = NULL;

    //con questa operazione elimino l'elemento all'indice desiderato
    
    temp_node = current -> next;
    current -> next = temp_node -> next;
    free(temp_node);    
    
    return 0;
}