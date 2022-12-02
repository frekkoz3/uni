#include <stdio.h>

void scambia (int *p, int i, int j){    //FUNZIONE CHE SCAMBIA VALORI IN UN ARRAY SFRUTTANDO LE PROPRIETA' DEI PUNTATORI

    int t = *(p+i);
    *(p+i) = *(p+j);
    *(p+j) = t;
    
}

int main(){



    return 0;
}