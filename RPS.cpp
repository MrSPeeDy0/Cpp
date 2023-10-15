#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        cout << "Enter your choice (rock, paper, scissors) or type 'exit' to quit: ";
        string userChoice;
        cin >> userChoice;

        if (userChoice == "exit") {
            break;
        }

        cout << "Shuffling... ";
        delay(1000);

        int computerChoice = rand() % 3; // 0 for rock, 1 for paper, 2 for scissors

        if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors") {
            cout << "Computer's choice: ";
            delay(500);
            switch (computerChoice) {
                case 0:
                    cout << "Rock\n";
                    break;
                case 1:
                    cout << "Paper\n";
                    break;
                case 2:
                    cout << "Scissors\n";
                    break;
            }

            delay(500);
            if ((userChoice == "rock" && computerChoice == 2) || (userChoice == "paper" && computerChoice == 0) || (userChoice == "scissors" && computerChoice == 1)) {
                cout << "You win!\n";
            } else if (userChoice == "rock" && computerChoice == 1 || userChoice == "paper" && computerChoice == 2 || userChoice == "scissors" && computerChoice == 0) {
                cout << "Computer wins!\n";
            } else {
                cout << "It's a tie!\n";
            }
        } else {
            cout << "Invalid input. Please enter 'rock,' 'paper,' 'scissors,' or 'exit'.\n";
        }
    }

    cout << "Goodbye! Thanks for playing!\n";
    return 0;
}
