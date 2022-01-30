#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void write_bytes(int fd)
{
  for (int i = 0; i < 100; i++)
    write (fd, &b, 1)
}

int main(int argc, char** argv)
  {
  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    write_bytes(fd, 'a');
    exit(0);
  }
  write_bytes(fd, 'b');
  wait(NULL);
  }

      if(!fork())
    {
        close(1);
          
        dup2(fd[1], 1);
          
        close(fd[0]);
          
        execlp("ls","ls", "-la", argv[1], NULL);
    }
    else
    {
        close(0);
          
        dup2(fd[0], 0);
          
        close(fd[1]);
          
        execlp("wc","wc", "-l", NULL);
    }
}