#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;



void back_track(vector<int>& queen, vector<short>& coluna
, vector<short>& Adiagonal, vector<short>& Bdiagonal, 
int i, bool& stop);


void setup_back_track(int n, vector<int>& queen, vector<short>& coluna, 
vector<short>& Adiagonal, vector<short>& Bdiagonal);

void print_board(vector<int>& queen);

int main()
{
    vector<int> queen;
    vector<short> coluna, Adiagonal, Bdiagonal;
    int n;
    bool stop = false;

    cout << "Entre com o tamanho do tabuleiro: ";
    cin >> n;
    cout << endl;

    setup_back_track(n, queen, coluna, Adiagonal, Bdiagonal);

    back_track(queen, coluna, Adiagonal, Bdiagonal, 0, stop);

    cout << endl;
    return 0;
}

void print_board(vector<int>& queen) {
    int n(queen.size());
    int i, j;

    /* Imprima a resposta*/
    for (i=0; i< n; ++i) {
        for(j = 0; j < n; ++j) {
            if(queen[i] == j) {
                cout<< setw(3) << "Q";
            }
            else cout << setw(3) << "#";
        }
        cout << endl;
    }

    /* Imprima a resposta destacando o 1 conjunto de diagonais*/
    cout << endl << endl;
    for (i = 0; i<n; ++i) {
        for (j = 0; j<n; ++j) {
            if (queen[i] == j) {
                cout << setw(3) << "Q";
        
            }
            else cout << setw(3) << (i+j);
        }
        cout << endl;
    }

    /* Imprima a respota destancando o 2 conjunto de diagonais */

    cout << endl << endl;
    for (i = 0; i<n; ++i) {
        for (j = 0; j<n; ++j) {
            if (queen[i] == j) {
                cout << setw(3) << "Q";
            }
            else cout << setw(3) << (i-j+7);
        }
        cout << endl;
    }

}

void setup_back_track(int n, vector<int> &queen, vector<short>& coluna, 
vector<short>& Adiagonal, vector<short>& Bdiagonal) {
    int i;
    queen.resize(n);
    coluna.resize(n);
    Adiagonal.resize((2*n) +1);
    Bdiagonal.resize((2*n) +1);

    for (i = n; --i>=0; ) {
        queen[i] = -1;
        coluna[i] = 1;
    }

    for (i = (2*n) +1; --i>=0;) {
        Adiagonal[i] = 1;
        Bdiagonal[i] = 1;
    }
}


void back_track(vector<int>& queen, vector<short>& coluna, 
vector<short>& Adiagonal, vector<short>& Bdiagonal, 
int i, bool& stop) 
{
    /*Exame da condição de Parada*/
    if(i == queen.size()) {
        print_board(queen);
        stop = true;
        return;
    }
    /*Testando cada colunba para a rainha da linha i*/
    for(int j=0; (j < queen.size()) && (!stop); j++) 
    {
        /*Se a coluna está disponivel, e as diagonais*/
        if ( (coluna[j]) && (Adiagonal[i+j])  && (Bdiagonal[i-j +7]) ) {

            /*Atribua a coluna j a linha i*/
            queen[i] = j;

            /*Assinale a ocupação das diagonais e colunas*/
            coluna[j] = 0;
            Adiagonal[i+j] = 0;
            Bdiagonal[i-j+7] = 0;

            back_track (queen, coluna,Adiagonal,Bdiagonal, i+1, stop);

            /*Desfaça a atribuição*/

            queen[i] = -1;

            /*Assinale a disponibiliade das diagonais e colunas*/
            coluna[j] = 1;
            Adiagonal[i+j] = 1;
            Bdiagonal[i-j + 7] =1;
        }
    }
}