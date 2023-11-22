#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

int main() {
    srand(time(nullptr)); // Seed the random number generator

    int guess;
    int secret;
    int attempts = 0;
    int minAttempts = INT_MAX;

    do {
        secret = rand() % 51; // Generate a random number in the range 0-50
        attempts = 1;
        std::cout << secret << std::endl;
        std::cout << "Welcome to the Game!" << std::endl;
        std::cout << "Guess the number between 0 and 50 (-1 to quit): ";

        while (true) {
            std::cin >> guess;

            if (guess == -1) {
                std::cout << "Exiting the game." << std::endl;
                break;
            }

            if (guess < 0 || guess > 50) {
                std::cout << "Number out of range. Please enter a valid number: ";
                continue;
            }

            attempts++;

            if (guess == secret) {
                std::cout << "Congratulations! You guessed the number " << secret << " in " << attempts << " attempts." << std::endl;

                if (attempts < minAttempts) {
                    minAttempts = attempts;
                }

                std::cout << "Your attempts in this game: " << attempts << std::endl;
                std::cout << "Highscore (minimum attempts in all games): " << minAttempts << std::endl;
                break;
            }
            else {
                if (guess - 20 >= secret || secret - 20 >= guess) {
                    std::cout << "Your guess is more than 20 greater than the secret number. Try again: ";
                }
                else if (guess - 10 >= secret || secret - 10 >= guess) {
                    std::cout << "Your guess is more than 10 greater than the secret number. Try again: ";
                }
                else {
                    std::cout << "Not quite. Keep guessing: ";
                }
            }
        }
    } while (guess != -1);

    return 0;
}
