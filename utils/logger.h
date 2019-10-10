#include <sys/time.h>

void logProcess(char * name, int processStartTime, struct timeval * processEndTime) {
  gettimeofday(processEndTime, NULL);
  printf("%s process life span: %d ms\n", name, (processEndTime->tv_usec - processStartTime));
}