#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    double s = 200;
    for(int i=0; i<n; i++)
        s += s*0.10;
    printf("serie vale %lf \n", s);
    return 0;
}