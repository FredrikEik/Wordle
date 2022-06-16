#include "wordle.h"

GuessResponse Wordle::guess(const std::string& word)
{
    // need to make functions for exact match and contains match
    if (word.length() == 5)
    {
        std::cout << "\nYou guessed: " << word << std::endl;

    }
    else
        std::cout << "5 letter word! Not " << word.length() << "!\n";
    
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
        std::cout << "Can not open: " << filename << std::endl;
        return {};
    }
    // else
        //std::cout << file.rdbuf(); //test input funker
    //Exits after this for some reason.

    while (std::getline(file, word))
        result.push_back(word);

    return result[std::rand() % result.size()];
}

std::string Wordle::exact_print(char c)
{
    //should print green
    std::stringstream ss;
    ss << "\033[1;32m" << c << "\033[0m";

    return ss.str();
}

std::string Wordle::contains_print(char c)
{
    //should print yellow
    std::stringstream ss;
    ss << "\033[1;33m" << c << "\033[0m";

    return ss.str();
}
