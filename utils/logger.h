#include <sys/time.h>
#include <stdio.h>

void logProcess(char * name, int processStartTime, struct timeval * processEndTime) {
  gettimeofday(processEndTime, NULL);
  // In Linux, Te `%d` should be changed to `%ld` for this logger to work.
  printf("%s process life span: %d ms\n", name, (processEndTime->tv_usec - processStartTime));
}