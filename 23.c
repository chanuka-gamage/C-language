#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main(){
	int pd[2];
	char name[50];
	int age;
	
	pipe(pd);
	
	
	pid_t pid=fork();
	
	if(pid > 0){
		
		printf("Enter the Student name");
		scanf("%s",name);
		printf("Enter the student age");
		scanf("%d",&age);
		write(pd[1],name,sizeof(name));
		write(pd[1],&age,sizeof(age));
		
		 
		
	}
	else{
		
		
		read(pd[0],name,sizeof(name));
		read(pd[0],&age,sizeof(age));
		printf("\n------Child process Output-------\n");
		printf("Children name :%s\n",name);
		printf("Children age : %d\n",age);
		
		
	}
}