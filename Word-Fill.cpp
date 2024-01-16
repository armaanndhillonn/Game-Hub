#include <iostream>
#include <string>// string class, used to represent and manipulate text, such as sentence content and user input.
#include <cstdlib>// standard general utilities library, used for pseudo-random number generation with srand() and rand().
#include <ctime>// time functions, used to seed the random number generator based on the current time with srand().
#include <algorithm>// algorithms library, used for the random_shuffle function to randomize the order of options in the game.

using namespace std;

//structure for defining the sentence, correct fill in the word and the wrong options.
struct Sentence {
    string sentence;
    string correctWord;
    string wrongOptions[2];
};

// function to display a sentence with shuffled options
void displaySentence(Sentence sentenceInfo) {
    // combine correct and incorrect options for shuffling
    string options[] = { sentenceInfo.correctWord, sentenceInfo.wrongOptions[0], sentenceInfo.wrongOptions[1] };

    // randomly shuffle the options
    random_shuffle(begin(options), end(options));

    // display sentence and shuffled options
    cout << "Sentence: " << sentenceInfo.sentence << endl;
    cout << "Options: ";
    for (const string& option : options) {
        cout << option << " ";
    }
    cout << endl;
}

int main() {
    // seed for random number generation
    srand(time(0));

    // player's score and playAgain flag
    int score = 0;
    string playAgain;

    // array of Sentence objects representing the game challenges
    Sentence sentences[] = {
        {"She ____ to the store yesterday.", "went", {"wents", "vent"}},
        {"The cat ____ on the windowsill.", "sits", {"sit", "sitting"}},
        {"I cannot believe it's ____ already.", "Friday", {"friday", "Fryday"}},
        {"His favorite color is ____.","blue", {"bleu", "car"}},
        {"We are going to the park ____.","tomorrow", {"Tomorrow", "next tommorow"}},
        {"The stars ____ in the east.", "rise", {"rises", "risen"}},
        {"I have a pet ____ named Fluffy.", "cat", {"crocodile", "great shark"}},
        {"He ____ his homework every day.", "completes", {"complete", "completed"}},
        {"They enjoy playing ____ in the park.", "soccer", {"Soccer", "video games"}},
        {"The ____ of the movie was unexpected.", "ending", {"over", "under"}}
    };

    // game loop
    do {
        // clear the console screen
        cout << "\033[2J\033[1;1H";
        cout << "Word Fill Grammar Challenge" << endl;
        cout << "===========================" << endl;
        cout << "In this game, you will be presented with sentences containing a blank space." << endl;
        cout << "Your task is to fill in the blank with the correct word from the given options." << endl;
        cout << "For each correct answer, you earn 1 point. Let's see how many points you can score!" << endl;


        // randomly select a sentence for the current round
        int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));
        Sentence currentSentence = sentences[index];

        // display the current sentence with shuffled options
        displaySentence(currentSentence);

        // player input for their guess
        string userGuess;
        cout << "Enter your guess: ";
        cin >> userGuess;

        // check if the guess is correct and update the score
        if (userGuess == currentSentence.correctWord) {
            cout << "Correct! You earn 1 point." << endl;
            score++;
        } else {
            cout << "Incorrect. The correct word is: " << currentSentence.correctWord << endl;
        }

        // display the current score
        cout << "Your current score: " << score << endl;

        // ask if the player wants to play again
        cout << "Do you want to play again? (Yes/No): ";
        cin >> playAgain;

    } while (playAgain == "Yes" || playAgain == "yes");

    // display final score when the player decides not to play again
    cout << "Thanks for playing! Your final score is: " << score << endl;

    return 0;
}
