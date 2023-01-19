#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "led.h"

// #define JOYSTICK_UP_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio26/value"
// #define JOYSTICK_DOWN_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio46/value"
// #define JOYSTICK_LEFT_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio65/value"
// #define JOYSTICK_RIGHT_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio47/value"

void intro(void)
{
  printf("CMPT 433 | Kiaan Castillo | Assignment 1\n");
  printf("----------------------------------------\n");
  printf("\n");
  printf("Welcome to the LED game!\n");
  printf("When the LEDs light up, press the joystick in that direction!\n");
  printf("To exit the game, press the joystick left or right.\n");
  printf("Good luck and have fun!\n");
  printf("----------------------------------------\n");
  printf("\n");
}

// static long long getTimeInMs(void)
// {
//   struct timespec spec;
//   clock_gettime(CLOCK_REALTIME, &spec);
//   long long seconds = spec.tv_sec;
//   long long nanoSeconds = spec.tv_nsec;
//   long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;

//   return milliSeconds;
// }

static void sleepForMs(long long delayInMs)
{
  const long long NS_PER_MS = 1000 * 1000;
  const long long NS_PER_SECOND = 1000000000;

  long long delayNs = delayInMs * NS_PER_MS;
  int seconds = delayNs / NS_PER_SECOND;
  int nanoseconds = delayNs % NS_PER_SECOND;

  struct timespec reqDelay = {seconds, nanoseconds};
  nanosleep(&reqDelay, (struct timespec *)NULL);
}

static int getRandomTimeInMs() {
  int minInMs = 500;  // 0.5s
  int maxInMs = 3000; // 3s
  int denominator = (maxInMs + 1 - minInMs);

  return rand() % denominator + minInMs;
}

// static void runCommand(char *command)
// {
//   // Execute the shell command (output into pipe)
//   FILE *pipe = fopen(command, "r");

//   // Ignore output of the command; but consume it
//   // so we don't get an error when closing the pipe.
//   char buffer[1024];
//   while (!feof(pipe) && !ferror(pipe))
//   {
//     if (fgets(buffer, sizeof(buffer), pipe) == NULL)
//       break;
//     printf("--> %s", buffer); // Uncomment for debugging
//   }

//   // Get the exit code from the pipe; non-zero is an error:
//   int exitCode = WEXITSTATUS(pclose(pipe));
//   if (exitCode != 0)
//   {
//     perror("Unable to execute command:");
//     printf(" command: %s\n", command);
//     printf(" exit code: %d\n", exitCode);
//   }
// }

int main()
{
  //  1. Print a “get ready” message and turn on the middle two LEDs on BBG.
  intro();
  initializeAllLEDs();
  turnOffAllLEDs();
  printf("Get ready!\n");
  sleepForMs(getRandomTimeInMs());
  initializeAllLEDs();
  int direction = getRandomDirectionUpOrDown();
  turnOnLED(direction);
  if (direction == UP)
  {
    printf("Press UP now!\n");
  }
  else
  {
    printf("Press DOWN now!\n");
  }
  initializeAllLEDs();
  turnOffAllLEDs();

  return 0;
}
