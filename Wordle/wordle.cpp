#include "wordle.h"

GuessResponse Wordle::guess(const std::string& word)
{
    std::cout << "\nsecret word for debug purposes: " << secret_word;
    // need to make functions for exact match and contains match
    if (word.length() == 5)
    {
        attempts++;
        std::cout << "\nYou guessed: " << word << std::endl;
        for (unsigned int i = 0; i < word.length(); i++)
        {
            if (word[i] == secret_word[i])
            {
                std::cout << exact_print(word[i]);
            }
            //searches until the end of string
            //check if its correct character but is in the wrong spot
            else if (secret_word.find(word[i]) != std::string::npos)
            {
                std::cout << contains_print(word[i]);
            }
            //prints unmatched characters
            else
            {
                std::cout << same_print(word[i]);
            }
        }
    }
    else
        std::cout << "\n5 letter word! Not " << word.length() << "!\n";
    if (word == secret_word)
        gameWon(true);
    if (attempts >= max_attempts)
        gameLost(true);
    return {false, word};
}

std::string Wordle::get_word(const std::string& filename)
{
    std::srand(std::time(nullptr));

    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string word;

    if (!file.is_open())
    {
        std::cout << "\nCan not open: " << filename << std::endl;
        return {};
    }

    while (std::getline(file, word))
        result.push_back(word);
  

    return result[std::rand() % result.size()];
}

std::string Wordle::exact_print(char c)
{

    std::stringstream ss;
    ss << "\033[1;32m" << c << "\033[0m";
    return ss.str();
}

std::string Wordle::contains_print(char c)
{

    std::stringstream ss;
    ss << "\033[1;33m" << c << "\033[0m";

    return ss.str();
}

std::string Wordle::same_print(char c)
{
    std::stringstream ss;
    ss << c;
    return ss.str();
}

bool Wordle::gameWon(bool b)
{
    if (b)
    {
        game_active = false;
        std::cout << "\nYOU WON! Attempts used: " << attempts << ".\n";
    }
    return game_active;
}

bool Wordle::gameLost(bool b)
{
    if (b)
    {
        game_active = false;
        std::cout << "\nYOU LOST! The hidden word was: " << secret_word << ".\n";
    }

    return game_active;
}
