#include <stdbool.h>

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#define FILE_READ_BUFFER_MAX_LENGTH 2

#define JOYSTICK_UP_VALUE "/sys/class/gpio/gpio26/value"
#define JOYSTICK_UP_CONFIG_PIN "config-pin p8.14 gpio"
#define JOYSTICK_UP_INPUT "sys/class/gpio/gpio26/input"

#define JOYSTICK_DOWN_VALUE "/sys/class/gpio/gpio46/value"
#define JOYSTICK_DOWN_CONFIG_PIN "config-pin p8.16 gpio"
#define JOYSTICK_DOWN_INPUT "sys/class/gpio/gpio46/input"

#define JOYSTICK_LEFT_VALUE "/sys/class/gpio/gpio65/value"
#define JOYSTICK_LEFT_CONFIG_PIN "config-pin p8.18 gpio"
#define JOYSTICK_LEFT_INPUT "sys/class/gpio/gpio65/input"

#define JOYSTICK_RIGHT_VALUE "/sys/class/gpio/gpio47/value"
#define JOYSTICK_RIGHT_CONFIG_PIN "config-pin p8.15 gpio"
#define JOYSTICK_RIGHT_INPUT "sys/class/gpio/gpio47/input"

void runConfigPinOnAll(void);
void configureAllPinInputs(void);
void initializeAllPins(void);

bool isJoystickUpPressed(void);
bool isJoystickDownPressed(void);
bool isJoystickLeftPressed(void);
bool isJoystickRightPressed(void);

#endif