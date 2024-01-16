#include <iostream> 
#include <thread>// for the delay between the timer
#include <vector>// used for making the arrays 
#include <random>// used for the random aspect of choosing a symbol
#include <ctime>// used to get the current time (used for the random symbols, and duration of displaying symbols)

using namespace std;

const int MAX_SYMBOLS = 70; // maximum number of symbols that can be displayed.

// function to generate a random symbol from a predefined set
char generateRandomSymbol() {
    const string symbols = "!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int randomIndex = rand() % symbols.size();
    return symbols[randomIndex];
}

// function to display symbols for a given duration
void displaySymbols(int duration, const vector<char>& symbols) {
    cout << "Memorize these symbols:" << endl;
    for (char symbol : symbols) {
        cout << symbol;
    }
    cout << endl;

    // countdown for the specified duration
    for (int i = duration; i > 0; --i) {
        cout << "Time left: " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // clear the console screen
    cout << "\033[2J\033[1;1H";
}

// function to get user input for the remembered symbols
bool getUserInput(const vector<char>& symbols) {
    cout << "Enter the symbols you remember: ";

    string userInput;
    getline(cin, userInput);

    return userInput == string(symbols.begin(), symbols.end());
}

int main() {

    // introduction to the game
    cout << "Welcome symbol memory" << endl;
    cout << "Welcome to Symbol Memory! In this game, your task is to test and enhance your memory skills. You will be presented with a sequence of random symbols that you need to memorize within a set timeframe. Once the symbols disappear, your challenge is to input the correct sequence from memory. The difficulty increases as you decide to remember longer sequences." << endl;

    srand(static_cast<unsigned>(time(0)));  //seed for random symbol

    int displayDuration = 8; // duration symbol are displayed for
    int score = 0; // deafault score of player

    while (true) {
        // get the number of symbols the user wants to display
        int symbolCount;
        cout << "Enter the number of symbols (up to " << MAX_SYMBOLS << "): ";
        cin >> symbolCount;
        // validate user input
        if (symbolCount < 1 || symbolCount > MAX_SYMBOLS) {
            cout << "Invalid input. Please enter a positive integer less than or equal to " << MAX_SYMBOLS << "." << endl;
            cin.clear(); //clear all input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore anyinput till new line
            continue; //restart loop until valid input
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore input till new line

        // generating a sequence of random symbols
        vector<char> symbols;
        for (int i = 0; i < symbolCount; ++i) {
            symbols.push_back(generateRandomSymbol());
        }

        //show the randomly generated symbols and start the countdown
        displaySymbols(displayDuration, symbols);

        // take users sequence of symbols and compare it to the generated symbols
        if (getUserInput(symbols)) {
            cout << "Congratulations! You remembered the symbols. You win!" << endl;
            score++;
        } else {
            cout << "Sorry, you did not enter the correct symbols. The correct sequence was: ";
            //display correct sequence of symbols if user is incorrect
            for (char symbol : symbols) {
                cout << symbol;
            }
            cout << endl;
            cout << "You lose." << endl;
            cout << "Your score: " << score << endl;
        }

        //ask the user if they want to play again
        cout << "Do you want to play again? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) != 'y') {
            cout << "Thanks for playing! Your final score: " << score << endl;
            break; //break the loop if they choose not to play again
        }
    }
    return 0;
}
