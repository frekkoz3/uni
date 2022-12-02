#include <stdio.h>
#include <math.h>

double distanza(double x1, double y1, double x2, double y2);

int main(){

	double x1;
	double y1;
	double x2;
	double y2;
	
	scanf("%lf",&x1);
	scanf("%lf",&y1);
	scanf("%lf",&x2);
	scanf("%lf",&y2);

	printf("distanza tra i punti (%lf,%lf) (%lf,%lf) vale %lf \n", x1, y1, x2, y2, distanza(x1,y1,x2,y2));

	return 0;
}
double distanza(double x1, double y1, double x2, double y2){
	
	double param = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	double result = sqrt (param);
	return result;
	
}