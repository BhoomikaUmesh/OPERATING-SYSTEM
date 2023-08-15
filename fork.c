#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{ 
    pid_t pid;
    int status;
    
    // fork() system call
    pid = fork();
    
    if (pid < 0) {
        printf("Error: fork() failed.\n");
        return 1;
    } else if (pid == 0) {
        // child process
        
        printf("This is the child process with PID: %d\n", getpid());
        printf("Parent process PID: %d\n", getppid());
        
        // exec() system call
        execlp("/bin/ls", "ls", NULL);
        
        printf("This should not be printed if exec() is successful.\n");
        return 0;
    } else {
        // parent process
        
        printf("This is the parent process with PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
        
        // wait() system call
        wait(&status);
        
        printf("Child process exited with status: %d\n", status);
        
        return 0;
    }
}
/*Output
This is the parent process with PID: 15653
Child process PID: 15654
This is the child process with PID: 15654
Parent process PID: 15653
FCFS  FCFS.c  Priority  Priority.c  ProducerConsumer  ProducerConsumer.c  RR  RR.c  SJF  SJF.c  a.out  fork  fork.c  vfork.c
Child process exited with status: 0
*/