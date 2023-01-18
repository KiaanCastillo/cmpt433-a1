#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "led.h"

#define LED_UP_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED_UP_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr0/trigger"

#define LED_DOWN_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr3/brightness"
#define LED_DOWN_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr3/trigger"

#define LED_MIDDLE_1_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED_MIDDLE_1_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr1/trigger"

#define LED_MIDDLE_2_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED_MIDDLE_2_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr2/trigger"

#define JOYSTICK_UP_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio26/value"
#define JOYSTICK_DOWN_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio46/value"
#define JOYSTICK_LEFT_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio65/value"
#define JOYSTICK_RIGHT_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio47/value"

enum DIRECTION
{
  UP,
  DOWN
};

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

void turnOffAllLEDs(void)
{
}

static long long getTimeInMs(void)
{
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);
  long long seconds = spec.tv_sec;
  long long nanoSeconds = spec.tv_nsec;
  long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;

  return milliSeconds;
}

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

int getRandomWaitTimeInMs()
{
  int minInMs = 500;  // 5 milliseconds
  int maxInMs = 3000; // 3 seconds
  int denominator = minInMs + 1 - maxInMs;

  if (denominator != 0)
  {
    return minInMs + rand() % denominator;
  }

  printf("getRandomWaitTime() function is dividing by 0");
  exit(1);
}

int getRandomDirection()
{
  // int min = 0; // Up
  // int max = 1; // Down
  int denominator = UP + 1 - DOWN;

  if (denominator != 0)
  {
    return UP + rand() % denominator;
  }

  printf("getRandomDirection() function is dividing by 0");
  exit(1);
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

  // FILE *ledUp = fopen(LED_UP_BRIGHTNESS_FILE, "w");
  // FILE *ledDown = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
  // FILE *ledMiddle1 = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
  // FILE *ledMiddle2 = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");

  // FILE *joystickUp = fopen(JOYSTICK_UP_GPIO_DIRECTORY_PATH, "r");
  // FILE *joystickDown = fopen(JOYSTICK_DOWN_GPIO_DIRECTORY_PATH, "r");
  // FILE *joystickLeft = fopen(JOYSTICK_LEFT_GPIO_DIRECTORY_PATH, "r");
  // FILE *joystickRight = fopen(JOYSTICK_RIGHT_GPIO_DIRECTORY_PATH, "r");

  // runCommand("config-pin p8.26 gpio");
  // runCommand("config-pin p8.46 gpio");
  // runCommand("config-pin p8.65 gpio");
  // runCommand("config-pin p8.47 gpio");

  // if (ledUp == NULL)
  // {
  //   printf("Error accessing LED up\n");
  //   exit(1);
  // }

  // if (ledDown == NULL)
  // {
  //   printf("Error accessing LED down\n");
  //   exit(1);
  // }

  // if (ledMiddle1 == NULL)
  // {
  //   printf("Error accessing LED middle 1\n");
  //   exit(1);
  // }

  // if (ledMiddle2 == NULL)
  // {
  //   printf("Error accessing LED middle 2\n");
  //   exit(1);
  // }

  // if (joystickUp == NULL || joystickDown == NULL || joystickLeft == NULL || joystickRight == NULL)
  // {
  //   printf("Error accessing joysticks");
  //   exit(-1);
  // }

  while (1)
  {
    printf("Get ready...\n");
    turnOffAllLEDs();
    //  2. Wait a random amount of time between 0.5s and 3s.
    sleepForMs(getRandomWaitTimeInMs());

    //  3. If the user is already pressing up or down on the joystick, tell them “too soon” and repeat from step 1.
    // TODO

    //  4. Program picks a random direction (up or down) and print the direction.
    int direction = getRandomDirection();

    //  5. Display the program’s chosen direction on the BBG’s LEDs:
    //     - Turn off the middle two LEDs
    int charWrittenToLedMiddle1 = fprintf(ledMiddle1, "none");
    if (charWrittenToLedMiddle1 <= 0)
    {
      printf("Error turning off led middle 1");
      exit(1);
    }

    int charWrittenToLedMiddle2 = fprintf(ledMiddle2, "none");
    if (charWrittenToLedMiddle2 <= 0)
    {
      printf("Error turning off led middle 2");
      exit(1);
    }

    //     - If program chose up, then turn on the top LED (#0).
    if (direction == UP)
    {
      printf("Press UP now!\n");
      int charWrittenToLedUp = fprintf(ledUp, "1");

      if (charWrittenToLedUp <= 0)
      {
        printf("Error turning on led up");
        exit(1);
      }
      //     - If program chose down, then turn on the bottom LED (#3).
    }
    else if (direction == DOWN)
    {
      printf("Press DOWN now!\n");
      int charWrittenToLedDown = fprintf(ledDown, "1");

      if (charWrittenToLedDown <= 0)
      {
        printf("Error turning on led down");
        exit(1);
      }
    }

    //  6. Time how long it takes for the user to press the joystick in any direction.
    int startTimeInMs = getTimeInMs();

    //     - If timer > 5s, exit program with a message without waiting for a joystick press.
    do
    {
      // char joystickUpValue = fgetc(joystickUp);
      // char joystickDownValue = fgetc(joystickDown);
      // char joystickLeftValue = fgetc(joystickLeft);
      // char joystickRightValue = fgetc(joystickRight);

    } while (getTimeInMs() - startTimeInMs <= 5000);

    if (getTimeInMs() - startTimeInMs > 5000)
    {
      printf("Thanks for playing! See you next time.\n");
      break;
    }

    //  7. Process the user’s joystick press:
    //  a) If the user pressed up or down correctly, then:
    //    - print a message,
    //    - if this was the fastest correct response time yet the display that in a message,
    //    - display this attempt’s response time, and best so far (in ms),
    //    - flash all four LEDs on and off at 4hz for 0.5 seconds (two flashes).
    //  b) If the user pressed up or down incorrectly, print a message and flash all four LEDs on and off at 10hz for 1 second.
    //  c) If the user pressed left or right, print a message and quit
  }

  return 0;
}
