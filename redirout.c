#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void write_bytes(int fd)
{
  for (int i = 0; i < 100; i++)
    write (fd, &b, 1);
}

int main(int argc, char** argv)
  {
  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (pid == 0) {
    write_bytes(fd, 'a');
    exit(0);
  }
  write_bytes(fd, 'b');
  wait(NULL);

    int fd[2];
    // [0] is read
    // [1] is write
    pipe(fd);
  
    if(!fork()) //parent
    {
        close(1);
        // while read ! 0
        read(); // from input end to a buffer
        write(); // the buffer into output file opened at fd
        // end lop when 0 bytes return at EOF
        close(fd[0]); // close read end of pipe
        close(); // output file
    }
    else // child
    {
        close(0);
        dup2(fd[1], 1); // dup2 output to stdout
        close(fd[0]); // close read end of pipe
        execlp("wc","wc", "-l", NULL); // fix to execute argvs.
    }
}