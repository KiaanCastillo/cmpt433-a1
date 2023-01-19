#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helpers.h"
#include "led.h"
#include "joystick.h"

#define MAX_RESPONSE_TIME 5000

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

void endGame(void)
{
  printf("\n");
  printf("----------------------------------------\n");
  printf("Thanks for playing! See you next time.\n");
  turnOffAllLEDs();
}

int main()
{
  srand(time(NULL));
  intro();
  int fastestTime = 0;

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
      if ((isJoystickUpPressed() && direction == UP) || (isJoystickDownPressed() && direction == DOWN))
      {
        long long responseTime = getTimeInMs() - startTime;

        if (fastestTime == 0) {
          fastestTime = responseTime;
        } else if (fastestTime > responseTime) {
          fastestTime = responseTime;
          printf("NEW RECORD! ");
        }

        printf("Response time: %lldms\n", responseTime);
        printf("\n"); 

        break;
      }

      if ((isJoystickUpPressed() && direction != UP) || (isJoystickDownPressed() && direction != DOWN))
      {
        printf("Whoops, incorrect.\n");
        printf("\n"); 
        break;
      }

      if (isJoystickLeftPressed() || isJoystickRightPressed())
      {
        endGame();
        return 0;
      }
    } while (getTimeInMs() - startTime <= MAX_RESPONSE_TIME);

    if (getTimeInMs() - startTime > MAX_RESPONSE_TIME) {
      endGame();
      return 0;
    }
  }

  return 0;
}
