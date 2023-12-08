#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

class HangmanGame {
private:
    string wordList[10];
    string word;
    string guessed;
    string dispWord;
    int wordLength;
    int found;
    int tries;
    
    // Function to display Hangman
    void displayHangman() {
        cout << endl << endl;
        cout << "  -----" << endl;
        cout << "  |   |" << endl;
        cout << "  |"; if (tries < 5) cout  << "   O    "; cout << endl;
        cout << "  |"; if (tries <= 3) cout << "  /|\\"; cout << endl;
        cout << "  |"; if (tries <= 1) cout << "  / \\"; cout << endl;
        cout << "  |" << endl;
        cout << "__|__" << endl;
    }

public:
    HangmanGame() {
        srand(time(0));
        string wordList[10] = {
            "pakistan",
            "turkey",
            "azerbaijan",
            "malaysia",
            "bangladesh",
            "australia",
            "iran",
            "japan",
            "oman",
            "iraq"
        };
        word = wordList[rand() % 10];
        guessed = "";
        wordLength = word.length();
        dispWord = string(wordLength, 'X');
        found = 0;
        tries = 5;
    }

    // Function to play the game
    void playGame() {
        char guess;
        int flagFound;
        
        while (tries >= 0) {
            system("cls");
            cout << " Welcome to Hangman Game\n\n Guess a Country Name Or the Man will get hanged" << endl
                << endl << " Country Name: ";

            for (int i = 0; i < wordLength; i++) {
                cout << " " << dispWord[i];
            }
            cout << endl << endl << endl;

            cout << " Wrong Attempts: " << tries << " / " << 5 << endl;
            cout << " Already Guessed Letters: " << guessed << endl;

            displayHangman();

            if (found == wordLength) {
                cout << endl;
                cout << "*****************" << endl;
                cout << "**** You Win ****" << endl;
                cout << "*****************" << endl;
                break;
            }

            if (tries == 0) {
                break;
            }

            cout << "Guess a Letter: ";
            cin >> guess;

            guessed = guessed + " " + guess;

            if (dispWord.find(guess) != string::npos) {
                tries++;
            }

            flagFound = 0;

            for (int i = 0; i < wordLength; i++) {
                if (word[i] == guess && dispWord[i] == 'X') {
                    dispWord[i] = guess;
                    found++;
                    flagFound = 1;
                }
            }

            if (!flagFound) {
                tries--;
            }
        }

        if (found != wordLength) {
            cout << endl;
            cout << "************************" << endl;
            cout << "******* You Lose *******" << endl;
            cout << "*  Please Try Again :( *" << endl;
            cout << "************************" << endl;
        }

        system("pause");
    }
};

int main() {
    HangmanGame game;
    game.playGame();

    return 0;
}