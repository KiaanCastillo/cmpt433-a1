#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helpers.h"
#include "led.h"
#include "joystick.h"

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

    Direction direction = getRandomDirectionUpOrDown();
    turnOnLED(direction);

    long long startTime = getTimeInMs();

    do
    {
      printf("%d\n", isJoystickUpPressed());
      if ((isJoystickUpPressed() && direction == UP) || (isJoystickDownPressed() && direction == DOWN))
      {
        printf("Good job!\n");
        break;
      }
      else if (isJoystickLeftPressed() || isJoystickRightPressed())
      {
        printf("Thanks for playing!\n");
        return 0;
      }
    } while (getTimeInMs() - startTime <= 5000);

    printf("No response. Thanks for playing!\n");
    turnOffAllLEDs();
    return 0;
  }

  return 0;
}
