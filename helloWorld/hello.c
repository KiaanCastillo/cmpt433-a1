#include "game.h"

int main()
{
  initializeGame();

  while (1)
  {
    initializeRound();

    if (playerPressedTooEarly())
    {
      continue;
    }

    ROUND_RESULT roundResult = startRound();
    if (roundResult == START_NEW_ROUND)
    {
      continue;
    }
    else if (roundResult == END_GAME)
    {
      endGame();
      break;
    }
  }

  return 0;
}
