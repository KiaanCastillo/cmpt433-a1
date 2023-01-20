#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helpers.h"
#include "led.h"
#include "joystick.h"

#define MAX_RESPONSE_TIME_IN_MS 5000
#define CORRECT_ANSWER_LED_FLASH_DURATION_MS 500
#define INCORRECT_ANSWER_LED_FLASH_DURATION_MS 1000

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

void initializeGame(void)
{
  srand(time(NULL));
  intro();
  setAllLEDTriggersToNone();
  initializeAllPins();
}

void initializeRound(void)
{
  setAllLEDTriggersToNone();
  turnOffAllLEDs();
  printf("Get ready!\n");
  turnOnLEDMiddle1();
  turnOnLEDMiddle2();
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
  int fastestTime = 0;
  initializeGame();

  while (1)
  {
    initializeRound();

    turnOffAllLEDs();
    int waitTimeBeforeRoundStart = getRandomTimeInMs();
    int roundStartTime = getTimeInMs();
    bool pressedTooEarly = false;
    do
    {
      if (isJoystickUpPressed() || isJoystickDownPressed())
      {
        printf("Too soon!\n");
        printf("\n");
        pressedTooEarly = true;
        break;
      }
    } while (getTimeInMs() - roundStartTime < waitTimeBeforeRoundStart);

    if (pressedTooEarly)
    {
      continue;
    }

    Direction direction = getRandomDirectionUpOrDown();
    turnOnLED(direction);

    long long startTime = getTimeInMs();

    do
    {
      if ((isJoystickUpPressed() && direction == UP) || (isJoystickDownPressed() && direction == DOWN))
      {
        long long responseTime = getTimeInMs() - startTime;

        if (fastestTime == 0)
        {
          fastestTime = responseTime;
        }
        else if (fastestTime > responseTime)
        {
          fastestTime = responseTime;
          printf("NEW RECORD! ");
        }

        printf("Response time: %lldms\n", responseTime);
        printf("\n");
        correctAnswerLEDFlash();
        sleepForMs(CORRECT_ANSWER_LED_FLASH_DURATION_MS);

        break;
      }

      if ((isJoystickUpPressed() && direction != UP) || (isJoystickDownPressed() && direction != DOWN))
      {
        printf("Whoops, incorrect.\n");
        printf("\n");
        incorrectAnswerLEDFlash();
        sleepForMs(INCORRECT_ANSWER_LED_FLASH_DURATION_MS);

        break;
      }

      if (isJoystickLeftPressed() || isJoystickRightPressed())
      {
        endGame();
        return 0;
      }
    } while (getTimeInMs() - startTime <= MAX_RESPONSE_TIME_IN_MS);

    if (getTimeInMs() - startTime > MAX_RESPONSE_TIME_IN_MS)
    {
      endGame();
      return 0;
    }
  }

  return 0;
}
