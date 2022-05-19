// Guess my Number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1; // 
    int tries = 0;
    int guess;

    cout << "\tBem-vindo ao Adivinhe Meu Número\n\n";

    do
    {
        cout << "Digite um palpite: ";

        cin >> guess;
        ++tries;

        if (guess > secretNumber)
        {
            cout << "Muito alto!\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Muito baixo!\n\n";
        }
        else
        {
            cout << "\nÉ isso! Você conseguiu em " << tries << " suposições\n";
        }
    } while (guess != secretNumber);
    
    return 0;
}