#ifndef LED_H_
#define LED_H_

#define NUM_LEDS 4

#define LED_UP_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED_UP_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr0/trigger"
#define LED_UP_DELAY_ON_FILE "/sys/class/leds/beaglebone:green:usr0/delay_on"
#define LED_UP_DELAY_OFF_FILE "/sys/class/leds/beaglebone:green:usr0/delay_off"

#define LED_DOWN_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr3/brightness"
#define LED_DOWN_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr3/trigger"
#define LED_DOWN_DELAY_ON_FILE "/sys/class/leds/beaglebone:green:usr3/delay_on"
#define LED_DOWN_DELAY_OFF_FILE "/sys/class/leds/beaglebone:green:usr3/delay_off"

#define LED_MIDDLE_1_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED_MIDDLE_1_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr1/trigger"
#define LED_MIDDLE_1_DELAY_ON_FILE "/sys/class/leds/beaglebone:green:usr1/delay_on"
#define LED_MIDDLE_1_DELAY_OFF_FILE "/sys/class/leds/beaglebone:green:usr1/delay_off"

#define LED_MIDDLE_2_BRIGHTNESS_FILE "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED_MIDDLE_2_TRIGGER_FILE "/sys/class/leds/beaglebone:green:usr2/trigger"
#define LED_MIDDLE_2_DELAY_ON_FILE "/sys/class/leds/beaglebone:green:usr2/delay_on"
#define LED_MIDDLE_2_DELAY_OFF_FILE "/sys/class/leds/beaglebone:green:usr2/delay_off"

typedef enum
{
  UP,
  MIDDLE_1,
  MIDDLE_2,
  DOWN
} Direction;

void setAllLEDTriggersTo(char *value);
void setAllLEDTriggersToNone(void);
Direction getRandomDirectionUpOrDown(void);

void turnOnLEDUp(void);
void turnOnLEDDown(void);
void turnOnLEDMiddle1(void);
void turnOnLEDMiddle2(void);
void turnOnLED(Direction direction);
void turnOnAllLEDs(void);

void turnOffLEDUp(void);
void turnOffLEDDown(void);
void turnOffLEDMiddle1(void);
void turnOffLEDMiddle2(void);
void turnOffAllLEDs(void);

void setAllLEDDelayOnTo(char *value);
void setAllLEDDelayOffTo(char *value);
void correctAnswerLEDFlash(void);
void incorrectAnswerLEDFlash(void);

#endif
