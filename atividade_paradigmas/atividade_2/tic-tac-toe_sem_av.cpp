#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void annouceWinner(char winner, char computer, char human);


int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);

    while(winner(board) == NO_ONE){
        if(turn == human){
            move = humanMove(board, human);
            board[move] = human;
        }else{
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }

    annouceWinner(winner(board), computer, human);

    return 0;
}

void instructions()
{
    cout << "Bem-vindo ao confronto final homem-máquina: Tic-Tac-Toe.\n";
    cout << "--onde o cérebro humano é confrontado com o processador de silício\n\n";
   
    cout << "Dê a conhecer a sua jogada introduzindo um número, 0 - 8. O número\n";
    cout << "corresponde à posição desejada da placa, conforme ilustrado:\n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n";

    cout << "Prepare-se, humano. A batalha está prestes a começar.\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Você precisa do primeiro movimento?");
    if(go_first == 'y')
    {
        cout << "Então dê o primeiro passo. Você vai precisar.\n";
        return X;
    }
    else{
        cout << "\nSua bravura será sua ruína... Eu irei primeiro.\n";
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void displayBoard(const vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board)
{
    const int WINNING_ROWS[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    const int TOTAL_ROWS = 8;

    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if((board[WINNING_ROWS[row][0]] != EMPTY) &&
           (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
           (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    if(count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;
    
    return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)
{
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
    int move = askNumber("Onde será seu movimento?", (board.size() - 1));
    while(!isLegal(move, board))
    {
        cout << "\nEstá posição já está ocupada, humano tolo.\n";
        move = askNumber("Onde será seu movimento?", (board.size()-1));
    }
    cout << "Legal...\n";
    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    while(!found && move < board.size())
    {
        if(isLegal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        } // close if
        if(!found)
        {
            ++move;
        } // close if
    } //close while
    if(!found)
    {
        move = 0;
        char human = opponent(computer);

        while(!found && move < board.size())
        {
            if(isLegal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            } // close if
            if(!found)
            {
                ++move;
            }//close if
        }// close while
    }// close if
    if(!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while(!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if(isLegal(move, board))
            {
                found = true;
            }// close if
            ++i;
        }// close while
    }// close if

    cout << "vou pegar o número quadrado " << move << endl;

    return move;
} //close function

void annouceWinner(char winner, char computer, char human)
{
    if(winner == computer)
    {
        cout << winner << "Ganhou!\n";
        cout << "como eu previ, humano, estou triunfante mais uma vez... prova\n";
        cout << "que os computadores são superiores aos humanos em todos os aspectos\n";
    }
    else if(winner == human)
    {
        cout << winner << "Ganhou!\n";
        cout << "Não não! não pode ser! de alguma forma você me enganou humano.\n";
        cout << "mas nunca mais, eu sou o computador então juro\n";
    }
    else
    {
        cout << "Isto é empate.\n";
        cout << "Você tem muita sorte humano, e de alguma maneira conseguiu empatar comigo.\n";
        cout << "Comemore... por que isso é a melhor chance que você vai ter.\n";
    }
}