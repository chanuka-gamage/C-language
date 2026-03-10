#include<stdio.h>
#include<unistd.h>


int main(){
	
	
	
	int fd[2];
	pipe(fd);
	pid_t pid=fork();
	
	//parent
	if(pid > 0){
		char msg[]="Hello child";
		write(fd[1],msg,sizeof(msg));
	}
	//child
	else{
		char b[50];
		read(fd[0],b,sizeof(b));
		printf("Child received :%s\n",b);
	}
}