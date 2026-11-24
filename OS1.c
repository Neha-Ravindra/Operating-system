
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	
	pid=fork();
	
	if(pid<0){
		
		perror("fork failed");
		return 1;
	}
	else if (pid==0){
		
		printf("Cild process is executing \n");
		
		
		execl("/bin/pwd","pwd", NULL);
		
		perror("exec failed");
	}
	else{
	
		printf ("Parent process; waiting for child to complete\n");
		wait (NULL);
		printf("Child completed. Parent existing.\n");
	}
		return 0;
}
