#include <iostream>
#include <vector>
#include <utility>
#include <random>

namespace WordsList {
    std::vector<std::string> words {"mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
};

class Hangman {
private:
    std::string m_word { };
    std::vector<char> m_guesses { };
    int m_incorrectGuess { 0 };
    bool m_flag { false }; 
public:
    bool getFlag() { return m_flag; }
    int getGuesses() { return m_incorrectGuess; }
    std::string getTheWord() { return m_word; }
    void getWord();
    bool validateGuess(char guess);
    void displayProgress();
};

void Hangman::getWord() {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<size_t> dist{0, WordsList::words.size() - 1};
    m_word = WordsList::words[dist(gen)];
}

bool Hangman::validateGuess(char guess){
    if (static_cast<int>(guess) < 97 || static_cast<int>(guess) > 122) {
        std::cout << "\nInvalid input, please try again. ";
        return false;
    }
    auto findLetter {std::find(m_guesses.begin(), m_guesses.end(), guess)};
    if (findLetter != m_guesses.end()) {
        //return b/c exists
        std::cout << "You guess that already! Try again: ";
        return false;
    }
    auto findInWord {std::find(m_word.begin(), m_word.end(), guess)};
    if (findInWord == m_word.end()) {
        std::cout << "Incorrect guess! Try again!\n";
        m_incorrectGuess++;
        m_guesses.push_back(guess);
    }
    else {
        m_guesses.push_back(guess);
    }
    return true;
}

void Hangman::displayProgress() {
    m_flag = true;
    std::cout << "Word: ";
    for (const auto& letter : m_word) {
        auto findLetter {std::find(m_guesses.begin(), m_guesses.end(), letter)};
        if (findLetter != m_guesses.end()) {
            std::cout << letter << " ";
        }
        else {
            m_flag = false;
            std::cout << "_ ";
        }
    }
    std::cout << "\nRemaning guesses: " << 6 - m_incorrectGuess;
        
}


int main() {
    std::cout << "--------Welcome To Hangman!--------\n";
    Hangman game{};
    game.getWord();
    std::cout << "Your word is: ";
    game.displayProgress();
    char guess {};
    while(game.getFlag() == false && game.getGuesses() < 6) {
        std::cout << "Take a guess! : ";
        std::cin >> guess;
        game.validateGuess(guess);
        //std::cout << "Word: " << game.getTheWord();
        game.displayProgress();
    }
    
    return 0;
}