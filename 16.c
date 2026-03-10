#include<stdio.h>
#include<unistd.h>

int main(){
 int fd[2];
 pipe(fd);
 
 pid_t pid=fork();
 
 if(pid >0){
	 char name[50];
	 printf("Entetr your name :");
	 scanf("%s",name);
	 write(fd[1],name,sizeof(name));
 }
 else{
	 char n[50];
	 read(fd[0],n,sizeof(n));
	 printf("My name : %s",n);
 }
 }