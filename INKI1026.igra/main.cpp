#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

std::string getRandomWord(const std::vector<std::string>& words) {
    int index = std::rand() % words.size();
    return words[index];
}

int main() {
    std::ifstream file("zborovi.txt");
    if (!file) {
        std::cout << "Fajlot ne e dostapen." << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::string word;

    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    if (words.empty()) {
        std::cout << "Fajlot e prazen." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string wordToGuess = getRandomWord(words);
    int wordLength = wordToGuess.length();

    std::string guessedWord(wordLength, '_');

    int attempts = 0;
    bool guessed = false;

     std::cout << std::endl;
        std::cout<< "/////////////////////////////////////////"<< std::endl;
        std::cout<< "                  BESILKA"<< std::endl;
        std::cout<< "-----------------------------------------"<< std::endl;
        std::cout<< "            POGODI JA DRZAVATA"<< std::endl;
        std::cout<< "/////////////////////////////////////////"<< std::endl;
        std::cout << std::endl;

    while (!guessed) {
        std::cout << "Drzavata e: " << guessedWord << std::endl;

        std::cout << "Vnesi bukva: ";
        char guess;
        std::cin >> guess;


        guess = std::tolower(guess);

        bool correctGuess = false;
        for (int i = 0; i < wordLength; i++) {
            if (std::tolower(wordToGuess[i]) == guess) {
                guessedWord[i] = wordToGuess[i];
                correctGuess = true;
            }
        }

        if (guessedWord == wordToGuess) {
            guessed = true;
            std::cout << "Bravo! Go pogodivte zborot: " << wordToGuess << std::endl;
            std::cout << std::endl;
            std::cout << "     _____________ " << std::endl;
            std::cout << "    |             | " << std::endl;
            std::cout << "    |   o     o   | " << std::endl;
            std::cout << "    |             | " << std::endl;
            std::cout << "    |  (_______)  | " << std::endl;
            std::cout << "    |_____________| " << std::endl;
        } else if (correctGuess) {
            std::cout << "Bravo, zborot ja sodrzi ovaa bukva!" << std::endl;
        } else {
            std::cout << "Zalam, zborot ne ja sodrzi ovaa bukva!" << std::endl;
            attempts++;
        }

        std::cout << std::endl;

        if (attempts >= 5) {
            std::cout << "Go nadminavte maksimalniot broj na pogodoci! Zborot bese: " << wordToGuess << std::endl;
            std::cout << std::endl;
            std::cout << "     _____________ " << std::endl;
            std::cout << "    |             | " << std::endl;
            std::cout << "    |   o     o   | " << std::endl;
            std::cout << "    |   _______'  | " << std::endl;
            std::cout << "    |  (       )  | " << std::endl;
            std::cout << "    |_____________| " << std::endl;
            break;
        }
    }

    return 0;
}
