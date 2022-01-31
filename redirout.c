#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_CHAR 2048

int main(int argc, char** argv)
  {

  if(argc < 3) 
  {
    printf("Please enter more than three commands!");
		exit(1);
	}
  // open() output
  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    int fds[2];
    // [0] is read end
    // [1] is write end

    pipe(fds);
  
    if(!fork()) //parent
    {
        close(fds[1]);
        char buf[MAX_CHAR];
        int i;

        // loop for read/writing logic
        while (i > 0) 
        {
          i = read(fds[0], buf, sizeof buf); // from input end to a buffer
          write(fd, buf, i); // the buffer into the opened output file
        }
        close(fds[0]); // close() the read end of the pipe.
        close(fd); // close the file once complete. all done.
    }
    else // child
    {
        close(0);
        dup2(fds[1], 1); // dup2 output to stdout
        close(fds[0]); // close read end of pipe
        char * const *args = argv + 2;
        execvp(argv[2], args); // executes all args!
        exit(1);
    }
}