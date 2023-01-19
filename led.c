#include <stdio.h>
#include <stdlib.h>
#include "led.h"

static FILE *LEDUpBrightness;
static FILE *LEDUpTrigger;

static FILE *LEDDownBrightness;
static FILE *LEDDownTrigger;

static FILE *LEDMiddle1Brightness;
static FILE *LEDMiddle1Trigger;

static FILE *LEDMiddle2Brightness;
static FILE *LEDMiddle2Trigger;

void initializeAllLEDs(void);
void toggleLED(FILE *LED);

void turnOnLEDUp(void);
void turnOnLEDDown(void);
void turnOnLEDMiddle1(void);
void turnOnLEDMiddle2(void);

void turnOffLEDUp(void);
void turnOffLEDDown(void);
void turnOffLEDMiddle1(void);
void turnOffLEDMiddle2(void);

void initializeAllLEDs(void)
{
  LEDUpBrightness = fopen(LED_UP_BRIGHTNESS_FILE, "w");
  LEDDownBrightness = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
  LEDMiddle1Brightness = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
  LEDMiddle2Brightness = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");

  if (LEDUpBrightness == NULL || LEDDownBrightness == NULL || LEDMiddle1Brightness == NULL || LEDMiddle2Brightness == NULL)
  {
    printf("Error initializing LED brightness files \n");
    exit(1);
  }

  LEDUpTrigger = fopen(LED_UP_TRIGGER_FILE, "w");
  LEDDownTrigger = fopen(LED_DOWN_TRIGGER_FILE, "w");
  LEDMiddle1Trigger = fopen(LED_MIDDLE_1_TRIGGER_FILE, "w");
  LEDMiddle2Trigger = fopen(LED_MIDDLE_2_TRIGGER_FILE, "w");

  if (LEDUpTrigger == NULL || LEDDownTrigger == NULL || LEDMiddle1Trigger == NULL || LEDMiddle2Trigger == NULL)
  {
    printf("Error initializing LED trigger files \n");
    exit(1);
  }
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
  LEDUpBrightness = fopen(LED_UP_BRIGHTNESS_FILE, "w");
  int charWrittenToBrightness = fprintf(LEDUpBrightness, "1");
  if (charWrittenToBrightness <= 0)
  {
    printf("Error turning on brightness for LED up");
    exit(1);
  }
  fclose(LEDUpBrightness);

  // LEDUpTrigger = fopen(LED_UP_TRIGGER_FILE, "w");
  // int charWrittenToTrigger = fprintf(LEDUpTrigger, "none");
  // if (charWrittenToTrigger <= 0)
  // {
  //   printf("Error turning off trigger for LED up");
  //   exit(1);
  // }
  // fclose(LEDUpTrigger);
}

void turnOnLEDDown(void)
{
  LEDDownBrightness = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDDownBrightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED down");
    exit(1);
  }
  fclose(LEDDownBrightness);

  // LEDDownTrigger = fopen(LED_DOWN_TRIGGER_FILE, "w");
  // int charWrittenToTrigger = fprintf(LEDDownTrigger, "none");
  // if (charWrittenToTrigger <= 0)
  // {
  //   printf("Error turning off trigger for LED down");
  //   exit(1);
  // }
  // fclose(LEDDownTrigger);
}

void turnOnLEDMiddle1(void)
{
  LEDMiddle1Brightness = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle1Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 1");
    exit(1);
  }
  fclose(LEDMiddle1Brightness);

  // LEDMiddle1Trigger = fopen(LED_MIDDLE_1_TRIGGER_FILE, "w");
  // int charWrittenToTrigger = fprintf(LEDMiddle1Trigger, "none");
  // if (charWrittenToTrigger <= 0)
  // {
  //   printf("Error turning off trigger for LED middle 1");
  //   exit(1);
  // }
  // fclose(LEDMiddle1Trigger);
}

void turnOnLEDMiddle2(void)
{
  LEDMiddle2Brightness = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");
  int charWritten = fprintf(LEDMiddle2Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 2");
    exit(1);
  }
  fclose(LEDMiddle2Brightness);

  // LEDMiddle2Trigger = fopen(LED_MIDDLE_2_TRIGGER_FILE, "w");
  // int charWrittenToTrigger = fprintf(LEDMiddle2Trigger, "none");
  // if (charWrittenToTrigger <= 0)
  // {
  //   printf("Error turning off trigger for LED middle 2");
  //   exit(1);
  // }
  // fclose(LEDMiddle2Trigger);
}

void turnOnLED(Direction direction)
{
  switch (direction)
  {
  case UP:
    turnOnLEDUp();
    break;
  case MIDDLE_1:
    turnOnLEDMiddle1();
    break;
  case MIDDLE_2:
    turnOnLEDMiddle2();
    break;
  case DOWN:
    turnOnLEDDown();
    break;
  default:
    printf("Invalid direction");
  }
}

void turnOffLEDUp(void)
{
  LEDUpBrightness = fopen(LED_UP_BRIGHTNESS_FILE, "w");
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
  LEDDownBrightness = fopen(LED_DOWN_BRIGHTNESS_FILE, "w");
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
  LEDMiddle1Brightness = fopen(LED_MIDDLE_1_BRIGHTNESS_FILE, "w");
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
  LEDMiddle2Brightness = fopen(LED_MIDDLE_2_BRIGHTNESS_FILE, "w");
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
