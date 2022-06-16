#include "wordle.h"

int main()
{
  Wordle wordle("dict.txt");
  std::string player_guess;
  while (wordle.game_active)
  {
	  std::cin >> player_guess;
	  wordle.guess(player_guess);
	  std::cout << "\nGuess a 5 letter word!!\n";
  }

}
