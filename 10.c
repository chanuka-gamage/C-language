#include<stdio.h>
int main(){
	//single array
	int mynum[] ={25,50,75,10};
	printf("%d\n",mynum[0]);
	
	//array sizeof
	int length=sizeof(mynum)/sizeof(mynum[0]);
	printf("%d",length);
	
	//print array
	int i;
	for(i=0;i<5;i++){
		printf("%d\n",mynum[i]);
		
	//2D array
	int matrix[2][3]={{1,4,2},{3,6,8}};
	printf("%d\n",matrix[0][2]);
	}
	//strings
	char arr[]="Hello World!";
	printf("%s",arr);
}	
	