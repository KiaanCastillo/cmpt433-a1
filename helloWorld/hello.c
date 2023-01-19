#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "helpers.h"
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
  srand(time(NULL));
  intro();

  while (1)
  {
    turnOffAllLEDs();
    printf("Get ready!\n");
    turnOnLEDMiddle1();
    turnOnLEDMiddle2();

    sleepForMs(getRandomTimeInMs());
    turnOffAllLEDs();
    turnOnRandomLEDUpOrDown();

    long long startTime = getTimeInMs();

    do
    {

    } while (getTimeInMs() - startTime <= 5000);

    printf("Thanks for playing!\n");
    turnOffAllLEDs();
    return 0;
  }

  return 0;
}
