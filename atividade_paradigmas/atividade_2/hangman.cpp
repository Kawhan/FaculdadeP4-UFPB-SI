// Hangman
// The classic game of hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main ()
{
    // set-up
    const int MAX_WRONG = 8; // maxium number of incorrect guesses allowed

    vector<string> words; // collection of possible words to guess
    words.push_back("ADVINHE");
    words.push_back("FORCA");
    words.push_back("DIFICIL");
    words.push_back("POESIA");
    words.push_back("HISTORIA");
    words.push_back("MESA");
    words.push_back("AMANHA");
    words.push_back("TIJOLO");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";

    cout << "Bem-vindo ao Jogo da forca. Boa sorte!\n";

    // main loop 
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) 
    {
        cout << "\n\nVocê tem " << (MAX_WRONG - wrong);
        cout << " palpites incorretos sobrando. \n";
        cout << "\nVocê usou as seguintes letras::\n" << used << endl;
        cout << "\nAté agora, a palavra é:\n" << soFar << endl;

        char guess;
        cout << "\n\nDigite seu palpite: ";
        cin >> guess;
        guess = toupper(guess); // Make uppercase since secret word in upperCase
        while (used.find(guess) != string::npos)
        {
            cout << "\nVocê já usou esse palpite " << guess << endl;
            cout << "Digite seu palpite: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "Está correto! " << guess << " está na palavra.\n";

            // Update soFar to include newly guessed letter
            for(unsigned int i= 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
                
            }
        }
        else
        {
            cout << "Desculpa, " << guess << "não esta na palavra.\n";
            ++wrong;
        }
    }

    // shut down
    if (wrong == MAX_WRONG) 
        cout << "\nVocê foi enforcado!";
    else 
        cout << "\nVocê adivinhou!";
    
    cout << "\nA palavra era " << THE_WORD << endl;

    return 0;
}