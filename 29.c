//basic function with fork()

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void processDemo(){
	pid_t  pid =fork();//create a new process
	
	if(pid<0){
		printf("fork failed \n");
	}else if (pid==0){
		//child process
		printf("This is Child process \n");
		printf("Child PID : %d\n",getpid());
	}else{
		//parent process
		printf("This is parent process \n");
		printf("parent pid : %d\n",getpid());
		printf("Child Pid %d \n",pid);
	}
}

int j17(){
	processDemo();
}

	


































		