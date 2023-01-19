#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "helpers.h"
#include "joystick.h"

void runConfigPinOnAll(void) {
  runCommand(JOYSTICK_UP_CONFIG_PIN);
  runCommand(JOYSTICK_DOWN_CONFIG_PIN);
  runCommand(JOYSTICK_LEFT_CONFIG_PIN);
  runCommand(JOYSTICK_RIGHT_CONFIG_PIN);
}


void configureAllPinInputs(void) {
  FILE *joystickUpInput = fopen(JOYSTICK_UP_VALUE, "w");
  FILE *joystickDownInput = fopen(JOYSTICK_DOWN_VALUE, "w");
  FILE *joystickLeftInput = fopen(JOYSTICK_LEFT_VALUE, "w");
  FILE *joystickRightInput = fopen(JOYSTICK_RIGHT_VALUE, "w");

  if (joystickUpInput == NULL || joystickDownInput == NULL || joystickLeftInput == NULL || joystickRightInput == NULL)
  {
    printf("Error opening joystick input files \n");
    exit(1);
  }

  int numJoysticks = 4;
  for (int i = 0; i < numJoysticks; i++) {

    int charWrittenToJoystick = fprintf(joystickUpInput, "in");
    if (i == 1) {
      charWrittenToJoystick = fprintf(joystickDownInput, "in");
    } else if (i == 2) {
      charWrittenToJoystick = fprintf(joystickLeftInput, "in");
    } else if (i == 3) {
      charWrittenToJoystick = fprintf(joystickRightInput, "in");
    }

    if (charWrittenToJoystick <= 0) {
      printf("Error setting joystick input to in");
      exit(1);
    }
  }

  fclose(joystickUpInput);
  fclose(joystickDownInput);
  fclose(joystickLeftInput);
  fclose(joystickRightInput);
}


void initializeAllPins(void) {
  runConfigPinOnAll();
  configureAllPinInputs();
}

bool isJoystickUpPressed(void)
{
  FILE *joyStickUpValue = fopen(JOYSTICK_UP_VALUE, "r");
  if (joyStickUpValue == NULL)
  {
    printf("Error reading joy stick up value\n");
    exit(-1);
  }

  char value[FILE_READ_BUFFER_MAX_LENGTH];
  fgets(value, FILE_READ_BUFFER_MAX_LENGTH, joyStickUpValue);
  fclose(joyStickUpValue);

  if (atoi(value) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isJoystickDownPressed(void)
{
  FILE *joyStickDownValue = fopen(JOYSTICK_DOWN_VALUE, "r");
  if (joyStickDownValue == NULL)
  {
    printf("Error reading joy stick up value\n");
    exit(-1);
  }

  char value[FILE_READ_BUFFER_MAX_LENGTH];
  fgets(value, FILE_READ_BUFFER_MAX_LENGTH, joyStickDownValue);
  fclose(joyStickDownValue);

  if (atoi(value) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isJoystickLeftPressed(void)
{
  FILE *joyStickLeftValue = fopen(JOYSTICK_LEFT_VALUE, "r");
  if (joyStickLeftValue == NULL)
  {
    printf("Error reading joy stick up value\n");
    exit(-1);
  }

  char value[FILE_READ_BUFFER_MAX_LENGTH];
  fgets(value, FILE_READ_BUFFER_MAX_LENGTH, joyStickLeftValue);
  fclose(joyStickLeftValue);

  if (atoi(value) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isJoystickRightPressed(void)
{
  FILE *joyStickRightValue = fopen(JOYSTICK_RIGHT_VALUE, "r");
  if (joyStickRightValue == NULL)
  {
    printf("Error reading joy stick up value\n");
    exit(-1);
  }

  char value[FILE_READ_BUFFER_MAX_LENGTH];
  fgets(value, FILE_READ_BUFFER_MAX_LENGTH, joyStickRightValue);
  fclose(joyStickRightValue);

  if (atoi(value) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
