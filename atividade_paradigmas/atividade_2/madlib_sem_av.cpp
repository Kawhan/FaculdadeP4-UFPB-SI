// Mad-Lib
// Criar uma historia baseada nas entradas do usuario

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, int number, string bodyPart, string name_friend, string name_city, string food);

int main()
{
    cout << "bem-vindo ao Mad Lib. \n\n";
    cout << "responda às seguintes perguntas para ajudar a criar uma nova história.";

    string name = askText("Por favor, digite um nome: ");
    string  name_friend = askText("Por favor, digite um nome de um grande amigo: ");
    string name_city = askText("Por favor, digite um nome uma cidade: ");
    int number = askNumber("Por favor, coloque um numero alto: ");
    string bodyPart = askText("Por favor, digite uma parte do corpo: ");
    string food = askText("Por favor, digite um nome de uma comida muito gostosa: ");

    tellStory(name, number, bodyPart, name_friend, name_city, food);

    return 0;
}

string askText(string prompt)
{
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

int askNumber(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

void tellStory(string name, int number, string bodyPart, string name_friend, string name_city, string food)
{
    cout << "\n \nLa vem a sua historia, quer aprender uma lição ou esta aqui para perder teu tempo?Só deixando claro que você vai perder seu tempo kkkk!\n";
    cout << "Em um dia ensolarado dois amigos andavam juntos em uma rua localizada em ";
    cout << name_city << ".\n";
    cout << "O nome deles eram " << name << " e ";
    cout << name_friend << ". \n";
    cout << "O amigo " << name_friend << " olhou para o lado e disse 'Irmão estou com muita dor no(a) ";
    cout << bodyPart << " vou me sentar naquele banco ali e descansar um pouco. O amigo logo falou tranquilo vou ficar aqui te esperando. ";
    cout << "Passou 2 minutos e começou a juntar muitas pessoas em um restaurante do lado de uma arvore grande, " << name << " ficou curioso e foi olhar.\n";
    cout << "Eram mais ou menos " << number << " juntos nesse restaurante, chegando lá " << name << " perguntou o que estava acontecendo.\n";
    cout << "Um bebado que estava la respondeu, rapaz o dono do restaurante enloqueceu por causa de um(a) " << food << " que tinha acabado.E disse que iria matar quem falasse " << food << " para ele.\n";
    cout << name_friend << " viu que seu amigo estava perto de um restaurante e lembrou de sua comida favorita " << food << ". Como ele estava com muita dor começou a perguntar de longe em voz alta para " << name << " saber se lá tinha a comida.\n";
    cout << "Traduza o resto para saber o que aconteceu: Fin de l'histoire. Je vous ai dit que vous perdriez votre temps.";
}