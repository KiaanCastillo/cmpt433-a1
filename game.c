#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LED_FILE_NAME_UP "/sys/class/leds/beaglebone:green:usr0"
#define LED_FILE_NAME_DOWN "/sys/class/leds/beaglebone:green:usr3"
#define LED_FILE_NAME_MIDDLE_1 "/sys/class/leds/beaglebone:green:usr1"
#define LED_FILE_NAME_MIDDLE_2 "/sys/class/leds/beaglebone:green:usr2"

#define JOYSTICK_UP_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio26"
#define JOYSTICK_DOWN_GPIO_DIRECTORY_PATH "/sys/class/gpio/gpio26"

enum DIRECTION { 
  UP,
  DOWN
}

void intro() {
  printf("CMPT 433 | Kiaan Castillo | Assignment 1\n")
  printf("----------------------------------------\n")
  printf("\n")
  printf("When the LEDs light up, press the joystick in that direction!\n")
  printf("Welcome to the LED game!\n")
  printf("To exit the game, press the joystick left or right.\n")
  printf("Good luck and have fun!\n")
  printf("----------------------------------------\n")
  printf("\n")
}

static void sleepForMs(long long delayInMs) {
  const long long NS_PER_MS = 1000 * 1000;
  const long long NS_PER_SECOND = 1000000000;

  long long delayNs = delayInMs * NS_PER_MS;
  int seconds = delayNs / NS_PER_SECOND;
  int nanoseconds = delayNs % NS_PER_SECOND;

  struct timespec reqDelay = {seconds, nanoseconds};
  nanosleep(&reqDelay, (struct timespec *) NULL);
}

int getRandomWaitTimeInMs() {
  int minInMs = 500;   // 5 milliseconds
  int maxInMs = 3000;  // 3 seconds 
  return minInMs + rand() / (minInMs + 1 - maxInMs);
}

int getRandomDirection() {
  int min = 0; // Up
  int max = 1; // Down
  return UP + rand() / (UP + 1 - DOWN);
}

static long long getTimeInMs(void) {
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);
  long long seconds = spec.tv_sec;
  long long nanoSeconds = spec.tv_nsec;
  long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;
  
  return milliSeconds;
}

int main() {
  //  1. Print a “get ready” message and turn on the middle two LEDs on BBG.
  intro();

  FILE *ledUp = fopen(LED_FILE_NAME_UP, "w");
  FILE *ledDown = fopen(LED_FILE_NAME_DOWN, "w");
  FILE *ledMiddle1 = fopen(LED_FILE_NAME_MIDDLE_1, "w");
  FILE *ledMiddle2 = fopen(LED_FILE_NAME_MIDDLE_2, "w");

  if (ledUp == NULL) {
    printf("Error accessing LED up", LED_FILE_NAME_UP);
    exit(1);
  }

  if (ledDown == NULL) {
    printf("Error accessing LED down", LED_FILE_NAME_DOWN);
    exit(1);
  }

  if (ledMiddle1 == NULL) {
    printf("Error accessing LED middle 1", LED_FILE_NAME_MIDDLE_1);
    exit(1);
  }

  if (ledMiddle2 == NULL) {
    printf("Error accessing LED middle 2", LED_FILE_NAME_MIDDLE_2);
    exit(1);
  }

  while(1) {
    printf("Get ready...\n");
    //  2. Wait a random amount of time between 0.5s and 3s.
    sleepForMs(getRandomWaitTimeInMs());

    //  3. If the user is already pressing up or down on the joystick, tell them “too soon” and repeat from step 1.
    // TODO

    //  4. Program picks a random direction (up or down) and print the direction.
    int direction = getRandomDirection();

    //  5. Display the program’s chosen direction on the BBG’s LEDs:
    //     - Turn off the middle two LEDs
    int charWrittenToLedMiddle1 = fprintf(ledMiddle1, "none");
    if (charWrittenToLedMiddle1 <= 0) {
      printf("Error turning off led middle 1");
      exit(1);
    }

    int charWrittenToLedMiddle2 = fprintf(ledMiddle2, "none");
    if (charWrittenToLedMiddle2 <= 0) {
      printf("Error turning off led middle 2");
      exit(1);
    }

    //     - If program chose up, then turn on the top LED (#0).
    if (direction == UP) {
      printf("Press UP now!\n");
      int charWrittenToLedUp = fprintf(ledUp, "1");

      if (charWrittenToLedUp <= 0) {
        printf("Error turning on led up");
        exit(1);
      }
    //     - If program chose down, then turn on the bottom LED (#3).
    } else if (direction == DOWN) {
      printf("Press DOWN now!\n");
      int charWrittenToLedDown = fprintf(ledDown, "1");

      if (charWrittenToLedUp <= 0) {
        printf("Error turning on led down");
        exit(1);
      }
    }

    //  6. Time how long it takes for the user to press the joystick in any direction.
    int startTimeInMs = getTimeInMs();

    //     - If timer > 5s, exit program with a message without waiting for a joystick press.
    //  7. Process the user’s joystick press:
    //  a) If the user pressed up or down correctly, then:
    //    - print a message,
    //    - if this was the fastest correct response time yet the display that in a message,
    //    - display this attempt’s response time, and best so far (in ms),
    //    - flash all four LEDs on and off at 4hz for 0.5 seconds (two flashes).
    //  b) If the user pressed up or down incorrectly, print a message and flash all four LEDs on and off at 10hz for 1 second.
    //  c) If the user pressed left or right, print a message and quit

    
  }

  return 0;
}
