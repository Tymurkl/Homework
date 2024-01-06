#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int WORD_LENGTH = 5;

// Функція генерує випадкове слово з набору слів
string generateRandomWord() {
    static const string words[] = {"lemon", "melon", "apple", "grape", "water"};
    int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));
    return words[randomIndex];
}

// Функція для перевірки введеної відповіді
bool checkAnswer(const string& guess, const string& answer, int& attempts) {
    if (guess.length() != answer.length()) {
        cout << "Invalid word length!" << endl;
        return false;
    }

    vector<bool> isCorrect(guess.length());

    for (size_t i = 0; i < answer.length(); ++i) {
        if (guess[i] == answer[i]) {
            isCorrect[i] = true;
        }
    }

    string output;

    for (size_t i = 0; i < answer.length(); ++i) {
        if (isCorrect[i]) {
            output += toupper(guess[i]);
        } else {
            if (answer.find(guess[i]) != string::npos) {
                output += guess[i];
            } else {
                output += '*';
            }
        }
    }

    cout << output << endl;

    // Перевірка, чи вгадано слово
    bool isGuessed = all_of(isCorrect.begin(), isCorrect.end(), [](bool val) { return val; });

    if (isGuessed) {
        cout << "Congratulations! You guessed the word in " << attempts << " attempts." << endl;
    }

    return isGuessed;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Генеруємо слово
    string word = generateRandomWord();

    int attempts = 0;

    while (true) {
        attempts++;


        string guess;
        cout << "Enter a 5-letter word in English: ";
        cin >> guess;


        if (checkAnswer(guess, word, attempts)) {
            break;
        }
    }

    // Перезапускаємо гру
    char answer;
    cout << "Play again? (y/n): ";
    cin >> answer;
    if (answer == 'y') {
        main();
    }

    return 0;
}
