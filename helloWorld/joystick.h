#include <stdbool.h>

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#define FILE_READ_BUFFER_MAX_LENGTH 2

#define JOYSTICK_UP_VALUE "/sys/class/gpio/gpio26/value"
#define JOYSTICK_DOWN_VALUE "/sys/class/gpio/gpio46/value"
#define JOYSTICK_LEFT_VALUE "/sys/class/gpio/gpio65/value"
#define JOYSTICK_RIGHT_VALUE "/sys/class/gpio/gpio47/value"

bool isJoystickUpPressed(void);
bool isJoystickDownPressed(void);
bool isJoystickLeftPressed(void);
bool isJoystickRightPressed(void);

#endif