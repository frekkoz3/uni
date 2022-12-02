#include <stdio.h>
void stampaArray(int* a, int dim){
    for(int i=0; i<dim; i++)
        printf("%d ", *(a+i));
    printf("\n");
}
int contaMinoriDiK(int* a, int dim, int k){
    int c = 0;
    for(int i=0; i<dim; i++){
        if(*(a+i) < k)
            c++;
    }
    return c;
}
void ordinaRispettoK(int* a, int dim, int k){
    int dimMin = contaMinoriDiK(a, dim, k);
    int* minori = (int*)malloc(sizeof(int)*dimMin);
    int contaMin = 0;
    int dimMag = dim-dimMin;
    int* maggiori = (int*)malloc(sizeof(int)*dimMag);
    int contaMag = 0;
    int contaK = 0;
    for(int i=0; i<dim; i++){
        if(*(a+i) == k){
            contaK++;
        }else if(*(a+i) < k){
            *(minori+contaMin) = *(a+i);
            contaMin++;
        }else{
            *(maggiori+contaMag) = *(a+i);
            contaMag++;
        }
    }
    for(int i=0; i<dimMin; i++){
        *(a+i) = *(minori+i);
    }
    for(int i=0; i<contaK; i++){
        *(a+i+dimMin) = k;
    }
    for(int i=0; i<dimMag; i++){
        *(a+i+dimMin+contaK) = *(maggiori+i);
    }
}
int main(){
    int a[] = {3, 5, 2, 1, 6, 3, 8, 10, 2, 5};
    int k = 5; //assumo k = 5 senza farlo inserire
    ordinaRispettoK(a, 10, k);
    stampaArray(a, 10);
    return 0;
}//chiedere dello stack smashing detected