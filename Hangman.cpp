#include <iostream>
#include <string>
using namespace std;

//Function for the introduction, introduces game and exmplains the rules.
void intro() {
  cout << "██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗" << endl;
  cout << "██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║" << endl;
  cout << "███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║" << endl;
  cout << "██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║" << endl;
  cout << "██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║" << endl;
  cout << "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝" << endl;
  cout << " Welcome to the two player Hangman game" << endl;
  cout << "========================================" << endl;
  cout << "The rules are simple, you will be given a word and you will have to guess it letter by letter" << endl;
  cout << "Player 1 will enter a word and Player 2 will guess it" << endl;
  cout << "Number of guesses depend on the length of the word" << endl;
}
//Function to hide the word after chosen to prevent cheating.
void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

//Function to display image of 'hangman' when incorrect letter is guessed
void displayHangman(int wrongGuessCount) {
  switch (wrongGuessCount) {
    case 0:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 1:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 2:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << "  |    |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 3:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << " /|    |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 4:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << " /|\\  |" << endl;
      cout << "       |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 5:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << " /|\\  |" << endl;
      cout << " /     |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
    case 6:
      cout << "   ____" << endl;
      cout << "  |    |" << endl;
      cout << "  O    |" << endl;
      cout << " /|\\  |" << endl;
      cout << " / \\  |" << endl;
      cout << "       |" << endl;
      cout << "______ |" << endl;
      cout << "        " << endl;
      break;
  }
}

//Function to display the word with the correct letters guessed and underscores for the letters not guessed.
void displayWord(const string& word, const string& guess) {
  cout << "Word: " << guess << endl;
}

//Function to display the letters guessed and the number of guesses left.
char getGuess() {
  char letter;
  cout << "Guess a letter: " << endl;
  cin >> letter;
  return letter;
}

//Function to check if the letter guessed is in the word.
bool updateGuess(const string& word, string& guess, char letter) {
  bool correct = false;
  for (int i = 0; i < word.size(); i++) {
    if (word[i] == letter) {
      guess[i] = letter;
      correct = true;
    }
  }
  return correct;
}

//Function to check if the word has been guessed correctly.
void displayResult(const string& word, const string& guess) {
  if (guess == word) {
    cout << "You guessed the word: " << word << endl;
  } else {
    cout << "You ran out of tries. The word was: " << word << endl;
  }
}

//Main function that runs the functions
int main() {
  //Calling intro function
  intro();
  //Declaring word variable to create the word to be guessed
  string word;
  cout << "Enter a word to be guessed: " << endl;
  cin >> word;
  //Clearing screen to hide the word
  clearScreen();


  //Declaring guess variable to store the letters guessed, uses underscore to represent number of characters
  string guess(word.size(), '_');
  //Declaring wrongGuessCount variable to keep track of the number of wrong guesses
  int tries = word.size();
  //Declaring letter variable to store the letter guessed
  int wrongGuessCount = 0;

  //Loop to keep the game display hangman image and word until the word is guessed or the user runs out of tries
  while (tries > 0 && guess != word) {
    //Displaying hangman image and word
    displayHangman(wrongGuessCount);
    //Displaying word with correct letters guessed and underscores for letters not guessed
    displayWord(word, guess);

    //Getting letter guessed
    char letter = getGuess();

    //Updating guess with correct letter
    bool correct = updateGuess(word, guess, letter);

    //If letter is not in word, increment wrongGuessCount and display message
    if (!correct) {
      cout << "" << endl;
      cout << "Incorrect guess. ";
      cout << "" << endl;
      wrongGuessCount++;
    }

    //Decrementing tries
    tries--;
  }

  //Displaying result of game
  displayHangman(wrongGuessCount);
  displayResult(word, guess);

  return 0;
}

