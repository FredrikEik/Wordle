#include "wordle.h"

int main()
{
  Wordle wordle("dict.txt");
  //need to make game loop
  std::string player_guess;
  std::cout << "Guess a 5 letter word!!\n";
  std::cin >> player_guess;
  wordle.guess(player_guess);
}
