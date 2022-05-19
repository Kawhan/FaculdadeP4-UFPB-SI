#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 11;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = 
    {
        {"parede", "Você sente que está batendo a cabeça em alguma coisa?"},
        {"oculos", "Isso pode ajudá-lo a ver a resposta"},
        {"rebuscado", "Indo devagar, não é?"},
        {"persistente", "Continue assim"},
        {"confusao", "É disso que se trata o jogo"},
        {"banana", "Macacos come está fruta"},
        {"abobora", "Fruta famosa no halloween"},
        {"chapeu", "Fica na cabeça"},
        {"afrodite", "Deusa do Amor (Mitologia Grega)"},
        {"paris", "A cidade do amor"},
        {"genebra", "Capital da paz"}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];

    string jumble = theWord;
    int length = jumble.size();
    for(int i=0; i<length; i++)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tBem-vindo ao Word Jumble!\n\n";
    cout << "Desembaralhe as letras para formar uma palavra.\n";
    cout << "Digite 'hint' para uma dica.\n";
    cout << "Digite 'quit' para sair do jogo.\n\n";
    cout << "A bagunça é: " << jumble;

    string guess;
    cout << "\n\n Seu palpite: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Desculpe, não é isso.";
        }

        cout << "\n\nSeu palpite: ";
        cin >> guess;
    }

    if (guess == theWord)
    {
        cout << "\nÉ isso! Você adivinhou!\n";
    }

    cout << "\nObrigado por jogar";
    
    return 0;
}