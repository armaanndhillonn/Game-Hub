#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

// ANSI escape codes for text color
#define RED_TEXT "\033[1;31m"
#define BLUE_TEXT "\033[1;34m"
#define YELLOW_TEXT "\033[1;33m"
#define RESET_TEXT "\033[0m"

void shuffleArray(string arr[], int size) {
    random_shuffle(arr, arr + size);
}

string displayGameAndGetInput(string words[], string colors[], int size) {
    int index = rand() % size; 

    cout << "Word to be matched: ";

    // set the color associated with the word
  
    if (colors[index] == "Red") {
        cout << RED_TEXT << words[index];
    } else if (colors[index] == "Blue") {
        cout << BLUE_TEXT << words[index];
    } else if (colors[index] == "Yellow") {
        cout << YELLOW_TEXT << words[index];
    }

    cout << RESET_TEXT << endl;

    // shuffle words with randomized colors
    shuffleArray(words, size);
    for (int i = 0; i < size; ++i) {
        if (colors[i] == "Red") {
            cout << RED_TEXT << words[i];
        } else if (colors[i] == "Blue") {
            cout << BLUE_TEXT << words[i];
        } else if (colors[i] == "Yellow") {
            cout << YELLOW_TEXT << words[i];
        }

        cout << RESET_TEXT << " ";
    }

    cout << "\nEnter your answer: ";

    string userAnswer;
    cin >> userAnswer;

  // checks if word matches with chosen word
  string result = tolower(userAnswer[0]) == tolower(words[index][0]) ? "Correct" : "Incorrect";

  // wait for user to press enter before clearing the screen
  cout << "\nPress Enter to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();
  cout << "\x1B[2J\x1B[H";  // ANSI escape sequence to clear the screen

  return result;
  
}

  

int main() {
  // gets random int using current time for shufflearray
    srand(static_cast<unsigned int>(time(0)));
  
    cout << "Welcome to the " << RED_TEXT << "Color" << RESET_TEXT << " " << BLUE_TEXT << "Match" << RESET_TEXT << " " << YELLOW_TEXT << "Game" << RESET_TEXT << "!"" To play, match the color of the word provided with one of the 3 words. Type in which word matches." << endl;
    const int size = 3;
    string words[size] = {"Red", "Blue", "Yellow"};
    string colors[size] = {"Red", "Blue", "Yellow"};

    int score = 0;
    int totalQuestions = 5;

    for (int i = 0; i < totalQuestions; ++i) {
        string result = displayGameAndGetInput(words, colors, size);

        if (result == "Correct") {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer is: " << words[i % size] << endl;
        }
    }

    cout << "Game Over. Your final score is: " << score << "/" << totalQuestions << endl;
    if (score != totalQuestions) {
        cout << "You did not get all the answers correct. Try again!" << endl;
    } else {
        cout << "Congratulations! You got all the answers correct!" << endl;
    }
    
    return 0;
}
