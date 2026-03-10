/* float =%f
   int   =%d
   char  =%c
   text Array =%s
*/

#include <stdio.h>

int main(){
	int num=15;
	float n=12.22;
	char letter ='d';
	
	printf("My age %d \n My float %f \n My Letter %c ",num,n,letter);
	
	
	int x= 10,y=5,z=30;
	printf ("\n%d",x+y+z);
	
	//decimal point with float
	float myFloatNum = 3.5;

printf("%f\n", myFloatNum);   // Default will show 6 digits after the decimal point
printf("%.1f\n", myFloatNum); // Only show 1 digit
printf("%.2f\n", myFloatNum); // Only show 2 digits
printf("%.4f", myFloatNum);   // Only show 4 digits
	

}