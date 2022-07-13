#pragma once
#include <iostream>
#include <string>
#include <iomanip>

void printBoard(int[5][5]);
bool checkWinner(int[5][5]);
void find(int&, int&, int, int[5][5]);
void playerTurn(int);
void checkSquares(int, int, int, int, int, int, int, int[5][5]);