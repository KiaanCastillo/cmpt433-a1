#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helpers.h"
#include "led.h"
#include "joystick.h"
#include "game.h"

static int fastestTime = 0;

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

bool playerPressedTooEarly(void)
{
  long long waitTimeBeforeRoundStart = getRandomTimeInMs();
  long long roundStartTime = getTimeInMs();
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
  return pressedTooEarly;
}

ROUND_RESULT startRound(void)
{
  turnOffAllLEDs();
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

      printf("Good job!\n");
      printf("Response time: %lldms | Fastest so far: %dms\n", responseTime, fastestTime);
      printf("\n");
      correctAnswerLEDFlash();

      break;
    }

    if ((isJoystickUpPressed() && direction != UP) || (isJoystickDownPressed() && direction != DOWN))
    {
      printf("Whoops, incorrect.\n");
      printf("\n");
      incorrectAnswerLEDFlash();

      break;
    }

    if (isJoystickLeftPressed() || isJoystickRightPressed())
    {
      return END_GAME;
    }
  } while (getTimeInMs() - startTime <= MAX_RESPONSE_TIME_IN_MS);

  if (getTimeInMs() - startTime > MAX_RESPONSE_TIME_IN_MS)
  {
    return END_GAME;
  }

  return START_NEW_ROUND;
}

void endGame(void)
{
  printf("\n");
  printf("----------------------------------------\n");
  printf("Thanks for playing! See you next time.\n");
  turnOffAllLEDs();
  setAllLEDTriggersToNone();
}
