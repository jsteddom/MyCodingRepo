#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <optional>
#include <utility>

namespace WordsList {
    std::vector<std::string> words {"mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
};

void displayHangman(int guesses) {
    std::string head {(guesses > 0 ? "0" : "")};
    std::string body {(guesses > 0 ? "|" : "")};
    std::string lArm {(guesses > 0 ? "\\" : "")};
    std::string rArm {(guesses > 0 ? "/" : "")};
    std::string lLeg {(guesses > 0 ? "/" : "")};
    std::string rLeg {(guesses > 0 ? "\\" : "")};
    std::cout << "  - - - - - - " << std::endl;
    std::cout << " |           " << head << std::endl;
    std::cout << " |          " << lArm << body << rArm << std::endl;
    std::cout << " |          " << lLeg << " " << rLeg << std::endl;
    //std::cout << " ";
}
//template <typename T>
std::pair<std::string, std::vector<char>> getWord() {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist{0, 8};
    int randomWordIndex{dist(gen)};
    std::string chosenWord {WordsList::words[randomWordIndex]};
    std::vector<char> initialProgress (chosenWord.length());
    for (auto& i : initialProgress) {
        i = '_';
    }
    return {chosenWord, initialProgress};
}

void displayWord(const std::pair<const std::string, std::vector<char>>& gameInfo, int guesses, const std::vector<char>& lettersGuessed) {
    for (const auto& i : gameInfo.second) {
        std::cout << i << " ";    
    }
}

bool findLetter(const std::vector<char>& word, char findLetter){
    for (const auto& letter: word) {
        if (letter == findLetter) 
            return true;
    }
    return false;
}

std::optional<bool> printProgress(const std::string& word, const std::vector<char>& guesses, int guessCount) {
    bool finished {true};
    for (const auto& letter: word) {
        if (findLetter(guesses, letter)) {
            std::cout << letter << " ";
            continue;
        }
        finished = false;
        std::cout << "_ ";
    }
    std::cout << "Guesses left: " << 6 - guessCount;
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
    //displayHangman(6);
    std::pair<const std::string, std::vector<char>> gameInfo {getWord()};
    std::vector<char> lettersGuessed;
    std::cout << "--------Welcome To Hangman!--------\n";
    std::cout << "Your word is: ";
    displayWord(gameInfo, 0, lettersGuessed);
    int guessCount { 0 };
    char guess { };
    //displayWord(WordsList::words[randomWordIndex], 0);
    do {
        std::cout << "Enter a guess: ";
        std::cin >> guess;
        std::cout << "guess: " << guess << std::endl;
        auto check {std::find(lettersGuessed.begin(), lettersGuessed.end(), guess)};
        if (!validiateInput(guess)) {
            std::cout << "Invalid";
            continue;
        }
        if (check != lettersGuessed.end()) {
            std::cout << "You already guess that! Try again.\n";
            continue;
        }
        auto isElement {gameInfo.first.find(guess)};
        if (isElement == std::string::npos) {
            std::cout << "Wrong! Try again\n";
            lettersGuessed.push_back(guess);
            guessCount++;
        } 
        else {
            lettersGuessed.push_back(guess);
        }
        //std::cout << "Whoops! " << guessCount;
        if(printProgress(gameInfo.first, lettersGuessed, guessCount)) {
            break;
        }

    } while (guessCount < 6);
    if (guessCount < 6) {
        std::cout << "Congrats!";
    }
    else {
        std::cout << "Your word: " << gameInfo.first;
    }
    
    

    return 0;
}