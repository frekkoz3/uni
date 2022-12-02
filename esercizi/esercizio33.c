#include <stdio.h>
#include <stdlib.h>
//DOVREBBE FUNZIONARE MA NON L'HO PROVATO ANCORA
int bisearch(int* a, int sup, int inf, int x){
    int med = (sup+inf)/2;
    if(*(a+med) == x)
        return med;
    if(inf >= sup)
        return -1;
    if(*(a+med) > x)
        return bisearch(a, sup, med-1, x);
    return bisearch(a, med+1, inf, x);
}
int main(){
    
    return 0;
}