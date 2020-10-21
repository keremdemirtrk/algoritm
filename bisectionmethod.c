#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double F(double, double, double, double, double);
int main() {
	double a,b,c,d; //katsayýlar tanýmlandý.
	double x1,x2,xm;  
	double y1,y2,ym;
	printf("f(x)= a * x^3+ b * x^2 + c * x +d = ");
	printf("A yi giriniz :");
	scanf("%lf",&a);
	printf("B yi giriniz :");
	scanf("%lf",&b);
	printf("C yi giriniz :");
	scanf("%lf",&c);
	printf("D yi giriniz :");
	scanf("%lf",&d);
	printf("x1 i giriniz :"); //alt deðer
	scanf("%lf",&x1);
	printf("x2 yi giriniz :"); //üst deðer
	scanf("%lf",&x2);
//	int ix=0;


	while(ym!=0){
	xm = (x1 + x2) / 2; //ortanca deðer
		
		y1 = F(a,b,c,d,x1);
	
		y2 = F(a,b,c,d,x2);
			
		ym = F(a,b,c,d,xm);
	
		printf("x1: %lf \t xm: %lf \t x2: %lf \n", x1, xm, x2);
		printf("y1: %lf \t ym: %lf \t y2: %lf \n", y1, ym, y2);
	if(y1 * ym <0){
	
		x2 = xm;
	}
	else if(y2 * ym <0){
		x1 = xm;
	}
else if(ym == 0){
printf("kokunuz budur: %lf",xm );
	}
else if(y1*y2>0){
printf("kokunuz yoktur");
break;	
	}	
		}
	
			}
					double F(double a, double b, double c, double d, double x){    //iþlemin döndüðü nokta
						return a*x*x*x + b*x*x + c*x + d;
	
					}	


 
