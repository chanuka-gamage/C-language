#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


//fork with function

void childprocess(){
	printf("This is child process \n");
	printf("Child pid : %d\n",getpid());
}

void parentprocess(){
	printf("This is parent process \n");
	printf("parent pid : %d\n",getpid());
}

int main(){
	int pd[2];
	
	pid_t pid=fork();
	
	if(pid==0){
		childprocess();
	}else{
		parentprocess();
	}
}
	
