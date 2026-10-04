#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <optional>

namespace WordsList {
    std::vector<std::string> words {"mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
};

bool findLetter(const std::string& word, char findLetter){
    for (const auto& letter: word) {
        if (letter == findLetter) 
            return true;
    }
    return false;
}

std::optional<bool> printProgress(const std::string& word, const std::vector<char>& guesses) {
    bool finished {true};
    for (const auto& letter: word) {
        if (findLetter(word, letter)) {
            std::cout << letter << " ";
        }
        finished = false;
        std::cout << "_ ";
    }
    if (finished)
        return true;
}

bool validiateInput(char guess) {
    if (static_cast<int>(guess) < 97 || static_cast<int>(guess) > 122) {
        std::cout << "\nInvalid input, please try again. ";
        return false;
    }
    return true;
}


int main() {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist{0, 8};
    int randomWordIndex{dist(gen)};

    std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of pluses." << std::endl;
    std::cout << "The word: ";
    for (const auto& letter: WordsList::words[randomWordIndex]) {
        std::cout << "_ ";
    }

    int guessCount { 0 };
    char guess {' '};
    std::vector<char> guesses;

    do {
        std::cout << "Enter a guess: ";
        std::cin >> guess;
        auto check {std::find(guesses.begin(), guesses.end(), guess)};
        if (!validiateInput(guess)) {
            continue;
        }
        else if (check != guesses.end()) {
            std::cout << "You already guess that! Try again.\n";
            continue;
        }
        auto isElement {WordsList::words[randomWordIndex].find(guess)};
        if (!isElement) {
            std::cout << "Wrong! Try again\n";
            guesses.push_back(guess);
        }

    } while (guessCount < 6 || !printProgress(WordsList::words[randomWordIndex], guesses));

    return 0;
}