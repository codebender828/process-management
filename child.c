#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "./utils/logger.h"

/*
  This function accepts an integer argument from the parent
  process and then prints a string with number of iterations
  accepted in it's arguments.
*/
int main (int argc, char * argv[]) {
  FILE * fp;
  int i;
  int count;
  struct timeval startChild, endChild;
  int childStart;
  
  // Record child process start time.
  gettimeofday(&startChild, NULL);
  childStart = startChild.tv_usec;

  // Process exits if no arguments are passed from parent process.
  if (argc < 0) {
    printf("No arguments were passed. Exiting\n");
    exit(1);
  }
  
  // If argument value in passed, it's parsed into an integer
  count = atoi(argv[1]);

  // Taget file is opened to be written to.
  fp = fopen ("./out/output.txt", "w");

  for(i = 0; i < count; i++){
    fprintf (fp, "%d: Child process string.\n", i + 1);
  }

  // File is closed after writing.
  fclose (fp);
  
  // Log child process duration.
  logProcess("child", childStart, &endChild);
  return 0;
}