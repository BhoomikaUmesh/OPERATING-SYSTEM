#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
    else if(pid==0)
    {
        printf("child process:Hello,i am the child!\n");
        printf("child process:My PID is %d\n",getpid());
        printf("child process:My parent's PID is %d\n",getppid());
        _exit(0);
    }
    else
    {
        printf("parent process:Hello i am the parent!\n");
        printf("parent process:My PID is %d\n",getpid());
        printf("parent process:My child's PID is %d\n",pid);
        int status;
        waitpid(pid,&status, 0);
        if(WIFEXITED(status)){
            printf("Parent process: Child process terminated normally.\n");
        }else{
             printf("Parent process: Child process terminated abnormally.\n");
        }
    }
return 0;
}