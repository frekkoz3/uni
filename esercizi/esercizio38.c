#include <stdio.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void ordinamentoArmonico(int* a, int dim){
    
    for(int i=0; i<dim-1; i++){
        if(i%2 == 0){
            if(*(a+i) < *(a+i+1))
                swap(a+i, a+i+1);
        }else{
            if(*(a+i) > *(a+i+1))
                swap(a+i, a+i+1);
        }
    }
    
}
void stampaArray(int* a, int dim){
    for(int i=0; i<dim; i++)
        printf("%d ", *(a+i));
    printf("\n");
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ordinamentoArmonico(a, 10);
    stampaArray(a,10);
    return 0;
}