#include <stdlib.h>
#include <time.h>
#include "helpers.h"

long long getTimeInMs(void)
{
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);
  long long seconds = spec.tv_sec;
  long long nanoSeconds = spec.tv_nsec;
  long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;

  return milliSeconds;
}

void sleepForMs(long long delayInMs)
{
  const long long NS_PER_MS = 1000 * 1000;
  const long long NS_PER_SECOND = 1000000000;

  long long delayNs = delayInMs * NS_PER_MS;
  int seconds = delayNs / NS_PER_SECOND;
  int nanoseconds = delayNs % NS_PER_SECOND;

  struct timespec reqDelay = {seconds, nanoseconds};
  nanosleep(&reqDelay, (struct timespec *)NULL);
}

int getRandomTimeInMs(void)
{
  int minInMs = 500;  // 0.5s
  int maxInMs = 3000; // 3s
  int denominator = (maxInMs + 1 - minInMs);

  return rand() % denominator + minInMs;
}
