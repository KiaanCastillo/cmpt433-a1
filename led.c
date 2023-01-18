#include <stdio.h>
#include <stdlib.h>
#include "led.h"

static FILE *LEDUpBrightness;
static FILE *LEDDownBrightness;
static FILE *LEDMiddle1Brightness;
static FILE *LEDMiddle2Brightness;

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
    printf("Error initializing LEDs\n");
    exit(1);
  }
}

void turnOnLEDUp(void)
{
  int charWritten = fprintf(LEDUpBrightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED up");
    exit(1);
  }
}

void turnOnLEDDown(void)
{
  int charWritten = fprintf(LEDDownBrightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED down");
    exit(1);
  }
}

void turnOnLEDMiddle1(void)
{
  int charWritten = fprintf(LEDMiddle1Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 1");
    exit(1);
  }
}

void turnOnLEDMiddle2(void)
{
  int charWritten = fprintf(LEDMiddle2Brightness, "1");
  if (charWritten <= 0)
  {
    printf("Error turning on LED middle 2");
    exit(1);
  }
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
  int charWritten = fprintf(LEDUpBrightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED up");
    exit(1);
  }
}
void turnOffLEDDown(void)
{
  int charWritten = fprintf(LEDDownBrightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED down");
    exit(1);
  }
}

void turnOffLEDMiddle1(void)
{
  int charWritten = fprintf(LEDMiddle1Brightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED middle 1");
    exit(1);
  }
}

void turnOffLEDMiddle2(void)
{
  int charWritten = fprintf(LEDMiddle2Brightness, "0");
  if (charWritten <= 0)
  {
    printf("Error turning off LED middle 2");
    exit(1);
  }
}

void turnOffAllLEDs(void)
{
  turnOffLEDUp();
  turnOffLEDDown();
  turnOffLEDMiddle1();
  turnOffLEDMiddle2();
}
