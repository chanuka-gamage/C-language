#include<stdio.h>
#include<unistd.h>

int main(){
	
	int fd1[2];
	int fd2[2];
	int fd3[2];
	int fd4[2];
	
	
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	pipe(fd4);
	
	pid_t pid1=fork();
	
	if(pid1==0){
		char n[50];
		read(fd1[0],n,sizeof(n));
		printf("B %s\n",n);
		
		pid_t pid4=fork();
		
		
		if(pid4==0){
			char nn[50];
			read(fd3[0],nn,sizeof(nn));
			printf("D %s\n",nn);
		}
		else{
			pid_t pid5=fork();
			
			if(pid5==0){
				char nm[50];
				read(fd4[0],nm,sizeof(nm));
				printf("F %s\n",nm);
			}
			else{
				char msg4[]="hello 4";
				char msg5[]="hello 5";
				
				write(fd3[1],msg4,sizeof(msg4));
				write(fd4[1],msg5,sizeof(msg5));
			}
		}	
		
	}
	else{
		pid_t pid2=fork();
		
		if(pid2==0){
			char m[50];
			read(fd2[0],m,sizeof(m));
			printf("C %s\n");
		}
		else{
			char msg1[]="hello 2";
			char msg2[]="hello 3";
			
			printf("A\n");
			write(fd1[1],msg1,sizeof(msg1));
			write(fd2[1],msg2,sizeof(msg2));
		}
	}
}