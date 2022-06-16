#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using GuessResponse = std::pair<bool, std::string>;

class Wordle
{
 public:
	 //takes random word from dictionary and sets it as the rand word
  explicit Wordle(const std::string& dictionary)
  : secret_word(get_word(dictionary)) {}

  bool game_active = true;
  GuessResponse guess(const std::string& word);

 private:
  static std::string get_word(const std::string& filename);
  static std::string exact_print(char c);
  static std::string contains_print(char c);

  bool gameWon(bool b);
  bool gameLost(bool b);

  int attempts = 0;
  const int max_attempts = 6;

  std::string secret_word;
};
