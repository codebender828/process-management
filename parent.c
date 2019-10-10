#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "./utils/logger.h"

int main(int argc, char* argv[]) {
  // Main variables
  time_t now;
  struct timeval startChild, endChild, startMain, endMain;
  int mainStart, childStart;
  pid_t pid;
  pid_t child_pid;
  int status;

  // Record start time for main process
  gettimeofday(&startMain, NULL);
  mainStart = startMain.tv_usec;

  // Fork main process
  time (&now);
  printf("[FORK]: Forking at %s \n", ctime(&now));
  pid = fork();

  if (pid < 0) {
    // Error handler
    printf("ERROR: Could not create child process!\nExiting program...\n");
    exit(1);
  } else if (pid == 0) {

    // Child process
    child_pid = getpid();
    execv("child", &argv[0]);
    exit(0);
  }

  // Parent process
  waitpid(child_pid, &status, 0);
  logProcess("parent", mainStart, &endMain);
  return 0;
}
