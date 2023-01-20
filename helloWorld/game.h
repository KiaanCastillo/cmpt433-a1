#include <stdbool.h>

#ifndef GAME_H_
#define GAME_H_

#define MAX_RESPONSE_TIME_IN_MS 5000
#define CORRECT_ANSWER_LED_FLASH_DURATION_MS 500
#define INCORRECT_ANSWER_LED_FLASH_DURATION_MS 1000

typedef enum
{
  START_NEW_ROUND,
  END_GAME
} ROUND_RESULT;

void intro(void);
void initializeGame(void);
void initializeRound(void);
bool playerPressedTooEarly(void);
ROUND_RESULT startRound(void);
void endGame(void);

#endif
