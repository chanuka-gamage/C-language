#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1[2];
	int fd2[2];
	
	
	pipe(fd1);
	pipe(fd2);
	
	
	pid_t pid=fork();
	
	if(pid==0){
		//2 child
		char msg[50];
		read(fd1[0],msg,sizeof(msg));
		printf("process 2 received :%s\n",msg);
	}
	else{
		//3 child
		pid_t pid2=fork();
		
		if(pid2==0){
			char msg[50];
			read(fd2[0],msg,sizeof(msg));
			printf("process 3 received :%s\n",msg);
		}
		else{
			char msg1[]="Hello child 2";
			char msg2[]="Hello child 3";
			
			write(fd1[1],msg1,sizeof(msg1));
			write(fd2[1],msg2,sizeof(msg2));
			
			printf("process 1 sent message\n");
		}
	}
}
		