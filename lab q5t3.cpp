#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int pid = fork();
 if(pid > 0)
 {
  wait(NULL);
  printf("Parent %d\n",getpid());
 }

 else if (pid == 0)
 {
  cpid = fork();
  if (pid > 0)
  {
   wait(NULL);
   printf("Child 2 %d End\n",getpid());
  }

  else if (pid == 0)
  { printf("Child 3 %d End\n",getpid());
    exit(0);
  }

 }
}
