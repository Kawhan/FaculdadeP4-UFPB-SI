// Aventura personalizada

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    const int GOLD_PIECES = 900000;
    int adventures, killed, survivors;
    int death_leader = 1;
    string leader;

    // obter as informações
    cout << "Bem vindo ao Mundo de Edgard e seus tesouros \n \n";
    cout << "Preste atenção para que sua morte não seja certa, digite com sabedoria porque o destino depende de você \n";


    cout << "Para continuar informe quantos entram nessa jornada em Edgard: ";
    cin >> adventures;

    cout << "\nDigite quantos serão desafiados: ";
    cin >> killed;

    survivors = adventures - killed;

    cout << "\nDigite seu nome de aventureiro: ";
    cin >> leader;

    // conte a história
    cout << "\nUm grupo de " << adventures << " jovens que não tem medo da morte, encaram o seu fim!\n";

    cout << "-- em busca dos tesouros perdidos de Edgard terra dos dragões.\n\n";

    cout << "O grupo era lidero pelo famoso Orc terrível, " << leader << ".\n\n";

    cout << "No inicio da historia todos tinham desgosto pelo Orc e o odiavam, mesmo sendo o lider muitas das suas decisões eram contestadas.\n\n";

    cout << "Foi oferecido para os " << adventures << " aventureiros uma missão, analisar uma caverna de tesouros onde um antigo dragão morava em Synthya leste de Edgard,  e todos que estavam lá aceitaram, menos o lider Orc " << leader << " não aceitou, disse que era ouro dos tolos e que a vida dele importava mais!\n\n";

    cout << "Todos ficaram com raiva e a elfa do grupo falou que o lider ORC só pensava em sí mesmo, diante daquilo ele com toda sua ignorancia falou: EU VOU. \n\n";

    cout << "Todos foram no outro dia em busca de seu fim, o ORC foi ignorado toda a viagem, chegando na caverna todos olharam em volta e sentiram que algo estava errado, o lider " << leader << " se colocou na frente dos " << adventures << " e foi arremeçado por uma bola de fogo!\n\n";

    cout << "Um dragão gigante surge da caverna, o dragão que ali morava nunca tinha saido daquele local, o cheiro de morte pairava sobre o ar, o lider " << leader << " pede para que todos\n\n";

    cout << "Nesse momento o dragão os ataca, um grupo de " << survivors << " se separou, a elfa cai no chão seria seu fim\n\n";

    cout << "Naquele momento o lider ORC " << leader << " salta na frente do grupo, pega sua espada e em meio a sangue do dragão, o dragão morre em meio a gritos, todos estavam assustados e agradecem ao lider " << leader << " pela sua proteção\n\n";

    cout << "Porém ele não responde, no meio de um brilho vindo do fundo da caverna eles podem ver, que na verdade o ORC que antes era o lider e o mais distante tinha se sacrificado pelo grupo e pelos que dúvidavam de suas ordens, em meio aquele momento o dragão estava nos seus pés, porém ele tinha morrido sem mesmo cair no chão, estava em pé mesmo com suas ferridas\n\n";

    cout << "Apenas "<< death_leader << " morto, no final da caverna os aventureiros viram que tinha muito  ouro em torno de " << GOLD_PIECES << " moedas, mas não valia nem sequer 1 vida e agora entendiam a importancia do que tinha acontecido, nunca julgar o livro pela capa!\n\n";

    cout << "Eles ao chegar na cidade dividiram o dinheiro em torno de " << (GOLD_PIECES % adventures) << " tinha sobrado e resolveram fazer uma homenagem a seu lider, fazendo uma estátua contando sua historia em um mural em baixo, aquilo nunca resolveria a dor de arependimento que eles tinham, mas todos agoram sabiam sobre o Lider ORC " << leader << "e seu ato de heroismo.\n\n";

    cout << "No final " << survivors << " sobreviveram para contar essa história e cada um ficou com " << GOLD_PIECES / survivors << " moedas";

    return 0;
}