#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "joystick.h"

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
  return true;
}
bool isJoystickLeftPressed(void)
{
  return true;
}
bool isJoystickRightPressed(void)
{
  return true;
}
