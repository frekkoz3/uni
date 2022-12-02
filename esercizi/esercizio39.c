#include <stdio.h>
#include <math.h>

void switchRight(int* a, int dim){
    
    int t = *(a+0);
    for(int i=0; i<dim-1; i++)
        *(a+i) = *(a+i+1);
    *(a+dim-1) = t;
    
}

void switchLeft(int* a, int dim){
    
    int t = *(a+dim-1);
    for(int i=dim-1; i>0; i--)    
        *(a+i) = *(a+i-1);
    *(a+0) = t;
    
}

void kSwitch(int* a, int dim, int k){
    
    if(k<0){
        k = abs(k);
        for(int i=0; i < k; i++)
            switchLeft(a, dim);
    }else{
        for(int i=0; i<k; i++)
            switchRight(a, dim);
    }   
    
}
void stampaArray(int* a, int dim){
    
    for(int i=0; i<dim; i++)
        printf("%d ", *(a+i));
    printf("\n");
    
}
int main(){

    int a[] = {1, 2, 3, 4, 5};
    int k;
    scanf("%d", &k);
    kSwitch(a, 5, k);
    stampaArray(a, 5);
    return 0;
}