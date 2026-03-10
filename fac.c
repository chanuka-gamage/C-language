#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void factorialfunc(int n){
int fact=1;
int i;
if(n>0){
for(i=1;i<=n;i++){
	fact=fact*i;
}
printf("factorial value is :%d\n",fact);

}
else if(n==0){
	printf("Factorial value as 1\n");
}else {
	printf("factorial not defined, please enter positive integer");
}
}



int main(){
	int n;
	printf("Enter the number : ");
    scanf("%d",&n);
	
     factorialfunc(n);	
}

