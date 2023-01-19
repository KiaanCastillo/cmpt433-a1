#include <stdio.h>
#include <stdlib.h>
#include "led.h"

void setAllLEDTriggersToNone(void)
{
  FILE *LEDUpTrigger = fopen(LED_UP_TRIGGER_FILE, "w");
  FILE *LEDDownTrigger = fopen(LED_DOWN_TRIGGER_FILE, "w");
  FILE *LEDMiddle1Trigger = fopen(LED_MIDDLE_1_TRIGGER_FILE, "w");
  FILE *LEDMiddle2Trigger = fopen(LED_MIDDLE_2_TRIGGER_FILE, "w");

  if (LEDUpTrigger == NULL || LEDDownTrigger == NULL || LEDMiddle1Trigger == NULL || LEDMiddle2Trigger == NULL)
  {
    printf("Error initializing LED trigger files \n");
    exit(1);
  }

  int numLEDs = 4;
  for (int i = 0; i < numLEDs; i++) {

    int charWrittenToTrigger = fprintf(LEDUpTrigger, "none");
    if (i == MIDDLE_1) {
      charWrittenToTrigger = fprintf(LEDMiddle1Trigger, "none");
    } else if (i == MIDDLE_2) {
      charWrittenToTrigger = fprintf(LEDMiddle2Trigger, "none");
    } else if (i == DOWN) {
      charWrittenToTrigger = fprintf(LEDDownTrigger, "none");
    }

    if (charWrittenToTrigger <= 0) {
      printf("Error setting LED trigger to none");
      exit(1);
    }
  }

  fclose(LEDUpTrigger);
  fclose(LEDMiddle1Trigger);
  fclose(LEDMiddle2Trigger);
  fclose(LEDDownTrigger);
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
