#include "Two_squares_game.h"

using namespace std;
// global variables
int firstAtt, secondAtt, cont = 1;
bool winner;
int board[][5] = { {1, 2, 3, 4, 0}, {5, 6, 7, 8, 0}, {9, 10, 11, 12, 0}, {13, 14, 15, 16, 0}, {0, 0, 0, 0, 0} };
int cols, rows, cols2, rows2;

int main()
{
    system("cls");
    printBoard(board);

    while (true)
    {
        //  check if Draw or not
        if (cont == 9)
        {
            cout << "Draw";
            break;
        }
        winner = checkWinner(board);

        // cheak winning
        if (winner == true)
        {
            playerTurn(cont);
            cout << "you lost";
            break;
        }

        // take the two squares choosen by the player of his turn
        playerTurn(cont);
        do
        {
            cout << "Enter your first attemp:  ";
            cin >> firstAtt;
        } while (!firstAtt >= 1 && !firstAtt <= 16);

        do
        {
            cout << "Enter your second attemp:  ";
            cin >> secondAtt;
        } while (!secondAtt >= 1 && !secondAtt <= 16);
        checkSquares(firstAtt, secondAtt, cols, cols2, rows, rows2, cont, board);
    }
    return 0;
}
