#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int fd[2];
    // [0] is read
    // [1] is write
    pipe(fd);
  
    if(!fork()) //parent
    {
        close(1);
        dup2(fd[1], 1); // dup2 write end to stdout
        close(fd[0]); // close read end of pipe
        execlp("ls","ls", "-la", argv[1], NULL); // execlp ls -la @dir specified at argv[1]
    }
    else // child
    {
        close(0);
        dup2(fd[0], 0); // dup2 read to stdin
        close(fd[1]); // close write end of pipe
        execlp("wc","wc", "-l", NULL); // execlp wc -l
    }
}