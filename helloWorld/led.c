#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include "helpers.h"

void setAllLEDTriggersTo(char *value)
{
  FILE *LEDUpTrigger = fopen(LED_UP_TRIGGER_FILE, "w");
  FILE *LEDDownTrigger = fopen(LED_DOWN_TRIGGER_FILE, "w");
  FILE *LEDMiddle1Trigger = fopen(LED_MIDDLE_1_TRIGGER_FILE, "w");
  FILE *LEDMiddle2Trigger = fopen(LED_MIDDLE_2_TRIGGER_FILE, "w");

  if (LEDUpTrigger == NULL || LEDDownTrigger == NULL || LEDMiddle1Trigger == NULL || LEDMiddle2Trigger == NULL)
  {
    printf("Error opening LED trigger files \n");
    exit(1);
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    int charWritten;

    if (i == UP)
    {
      charWritten = fprintf(LEDUpTrigger, value);
    }
    if (i == MIDDLE_1)
    {
      charWritten = fprintf(LEDMiddle1Trigger, value);
    }
    else if (i == MIDDLE_2)
    {
      charWritten = fprintf(LEDMiddle2Trigger, value);
    }
    else if (i == DOWN)
    {
      charWritten = fprintf(LEDDownTrigger, value);
    }

    if (charWritten <= 0)
    {
      printf("Error setting LED trigger to %s", value);
      exit(1);
    }
  }

  fclose(LEDUpTrigger);
  fclose(LEDMiddle1Trigger);
  fclose(LEDMiddle2Trigger);
  fclose(LEDDownTrigger);
}

void setAllLEDTriggersToNone(void)
{
  setAllLEDTriggersTo("none");
}

Direction getRandomDirectionUpOrDown(void)
{
  int direction = rand() % 2;

  if (direction == UP)
  {
    return UP;
  }
  return DOWN;
}

void turnOnLEDUp(void)
{
  FILE *LEDUpBrightness = fopen(LED_UP_BRIGHTNESS_FILE, "w");
  int charWrittenToBrightness = fprintf(LEDUpBrightness, "1");
  if (charWrittenToBrightness <= 0)
  {
    printf("Error turning on brightness for LED up");
    exit(1);
  }
  fclose(LEDUpBrightness);
}

void turnOnLEDDown(void)
{
  FILE *LEDDownBrightness = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDDownBrightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED down");
    exit(1);
  }
  fclose(LEDDownBrightness);
}

void turnOnLEDMiddle1(void)
{
  FILE *LEDMiddle1Brightness = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle1Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 1");
    exit(1);
  }
  fclose(LEDMiddle1Brightness);
}

void turnOnLEDMiddle2(void)
{
  FILE *LEDMiddle2Brightness = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle2Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 2");
    exit(1);
  }
  fclose(LEDMiddle2Brightness);
}

void turnOnLED(Direction direction)
{
  switch (direction)
  {
  case UP:
    printf("Press UP now!\n");
    turnOnLEDUp();
    break;
  case MIDDLE_1:
    turnOnLEDMiddle1();
    break;
  case MIDDLE_2:
    turnOnLEDMiddle2();
    break;
  case DOWN:
    printf("Press DOWN now!\n");
    turnOnLEDDown();
    break;
  default:
    printf("Invalid direction");
  }
}

void turnOnAllLEDs(void)
{
  turnOnLEDUp();
  turnOnLEDMiddle1();
  turnOnLEDMiddle2();
  turnOnLEDDown();
}

void turnOffLEDUp(void)
{
  FILE *LEDUpBrightness = fopen(LED_UP_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDUpBrightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED up");
    exit(1);
  }
  fclose(LEDUpBrightness);
}

void turnOffLEDDown(void)
{
  FILE *LEDDownBrightness = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDDownBrightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED down");
    exit(1);
  }
  fclose(LEDDownBrightness);
}

void turnOffLEDMiddle1(void)
{
  FILE *LEDMiddle1Brightness = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle1Brightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED middle 1");
    exit(1);
  }
  fclose(LEDMiddle1Brightness);
}

void turnOffLEDMiddle2(void)
{
  FILE *LEDMiddle2Brightness = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle2Brightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED middle 2");
    exit(1);
  }
  fclose(LEDMiddle2Brightness);
}

void turnOffAllLEDs(void)
{
  turnOffLEDUp();
  turnOffLEDDown();
  turnOffLEDMiddle1();
  turnOffLEDMiddle2();
}

void setAllLEDDelayOnTo(char *value)
{
  FILE *LEDUpDelayOn = fopen(LED_UP_DELAY_ON_FILE, "w");
  FILE *LEDDownDelayOn = fopen(LED_DOWN_DELAY_ON_FILE, "w");
  FILE *LEDMiddle1DelayOn = fopen(LED_MIDDLE_1_DELAY_ON_FILE, "w");
  FILE *LEDMiddle2DelayOn = fopen(LED_MIDDLE_2_DELAY_ON_FILE, "w");

  if (LEDUpDelayOn == NULL || LEDDownDelayOn == NULL || LEDMiddle1DelayOn == NULL || LEDMiddle2DelayOn == NULL)
  {
    printf("Error opening LED delay on files\n");
    exit(1);
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    int charWritten;
    if (i == UP)
    {
      charWritten = fprintf(LEDUpDelayOn, value);
    }
    if (i == MIDDLE_1)
    {
      charWritten = fprintf(LEDMiddle1DelayOn, value);
    }
    else if (i == MIDDLE_2)
    {
      charWritten = fprintf(LEDMiddle2DelayOn, value);
    }
    else if (i == DOWN)
    {
      charWritten = fprintf(LEDDownDelayOn, value);
    }

    if (charWritten <= 0)
    {
      printf("Error setting LED delay on to %s", value);
      exit(1);
    }
  }

  fclose(LEDUpDelayOn);
  fclose(LEDMiddle1DelayOn);
  fclose(LEDMiddle2DelayOn);
  fclose(LEDDownDelayOn);
}

void setAllLEDDelayOffTo(char *value)
{
  FILE *LEDUpDelayOff = fopen(LED_UP_DELAY_OFF_FILE, "w");
  FILE *LEDDownDelayOff = fopen(LED_DOWN_DELAY_OFF_FILE, "w");
  FILE *LEDMiddle1DelayOff = fopen(LED_MIDDLE_1_DELAY_OFF_FILE, "w");
  FILE *LEDMiddle2DelayOff = fopen(LED_MIDDLE_2_DELAY_OFF_FILE, "w");

  if (LEDUpDelayOff == NULL || LEDDownDelayOff == NULL || LEDMiddle1DelayOff == NULL || LEDMiddle2DelayOff == NULL)
  {
    printf("Error opening LED delay off files\n");
    exit(1);
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    int charWritten;
    if (i == UP)
    {
      charWritten = fprintf(LEDUpDelayOff, value);
    }
    if (i == MIDDLE_1)
    {
      charWritten = fprintf(LEDMiddle1DelayOff, value);
    }
    else if (i == MIDDLE_2)
    {
      charWritten = fprintf(LEDMiddle2DelayOff, value);
    }
    else if (i == DOWN)
    {
      charWritten = fprintf(LEDDownDelayOff, value);
    }

    if (charWritten <= 0)
    {
      printf("Error setting LED delay off to %s", value);
      exit(1);
    }
  }

  fclose(LEDUpDelayOff);
  fclose(LEDMiddle1DelayOff);
  fclose(LEDMiddle2DelayOff);
  fclose(LEDDownDelayOff);
}

void LEDFlash(int numFlashes, int delayInMs)
{
  for (int i = 0; i < numFlashes; i++)
  {
    turnOnAllLEDs();
    sleepForMs(delayInMs);
    turnOffAllLEDs();
    sleepForMs(delayInMs);
  }
}

void correctAnswerLEDFlash(void)
{
  LEDFlash(4, 75);
}

void incorrectAnswerLEDFlash(void)
{
  LEDFlash(10, 25);
}
