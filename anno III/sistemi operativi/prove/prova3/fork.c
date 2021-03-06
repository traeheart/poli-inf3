/*
 * Illustrates system call fork
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc,char *argv[]){
  int tC, tF;
  pid_t pid;

  tC = atoi (argv[1]);
  tF = atoi (argv[2]);

  
  fprintf(stdout, "Main\n");
  fprintf (stdout, "PID=%d; Parent PID=%d\n", getpid(), getppid());

  pid = fork();
  if (pid == 0){
    // Child
    sleep (tC);

    fprintf(stdout, "\nChild\n");
    fprintf (stdout, "PID=%d; Parent PID=%d; ", getpid(), getppid());
    fprintf(stdout, "Returned Value=%d\n", pid);
  } else {
    // Father
    sleep (tF);

    fprintf(stdout, "\nFather\n");
    fprintf (stdout, "PID=%d; Parent PID=%d; ", getpid(), getppid());
    fprintf(stdout, "Returned Value=%d\n", pid);
  }

  return 0;
}
