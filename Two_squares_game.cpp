#include "Two_squares_game.h"
using namespace std;

//___________________________________________________________________________________
// function to determine the winner by comparing each two blocks beside each other are filled or not
bool checkWinner(int table[5][5])
{
    bool isWinner = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((table[i][j] != 0 && table[i][j + 1] != 0) || (table[i][j] != 0 && table[i + 1][j] != 0))
            {
                isWinner = false;
                return isWinner;
            }
        }
    }
    return isWinner;
}

//___________________________________________________________________________________
// function to find the block the user want by the number written on it
void find(int &x, int &y, int att, int table[5][5])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (table[i][j] == att)
            {
                x = i;
                y = j;
            }
        }
    }
}

//___________________________________________________________________________________
// function that print plyer turn
void playerTurn(int conter)
{
    if (conter % 2 == 1)
    {
        cout << "player 1:\n";
    }
    else
        cout << "player 2:\n";
}

//___________________________________________________________________________________
//  function that print the board
void printBoard(int table[5][5])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << setw(3) << table[i][j] << " | ";
        }
        cout << setw(3) << table[i][3] << endl;
    }
}
//___________________________________________________________________________________
void checkSquares(int att1, int att2, int x, int x2, int y, int y2, int counter, int table[5][5])
{
    try
    {
        //  check if the two squares beside each other
        if ((att2 == att1 + 1 || att2 == att1 - 1 || att2 == att1 + 4 || att2 == att1 - 4))
        {
            find(x, y, att1, table);
            // check if the square not selected before
            if (table[x][y] != 0)
            {
                find(x2, y2, att2, table);
                // check if the last square in the row is not selected with the first square in the row under it
                if (!((y == 3 && y2 == 0) || (y == 0 && y2 == 3)))
                {
                    table[x][y] = 0;
                    // check if the square not selected before
                    if (table[x2][y2] != 0)
                    {
                        table[x2][y2] = 0;
                        system("cls");
                        printBoard(table);
                        counter++;
                    }
                    else
                        throw "input Error";
                }
                else
                    throw "input Error";
            }
            else
                throw "input Error";
        }
        else
            throw "input Error";
    }
    catch (...)
    {
        system("cls");
        cout << "\ninput Error\n";
        printBoard(table);
    }
}