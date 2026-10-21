#include <iostream>
using namespace std;

#define N 4

int board[N][N] = {0};
int Count = 0;

bool isSafe(int row, int col)
{
    for (int j = 0; j < col; j++)
        if (board[row][j] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row + 1, j = col - 1; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

void printBoard()
{
    Count++;
    cout << "Solution " << Count << ":\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}

void solveNQueens(int col)
{
    if (col == N)
    {
        printBoard();
        return;
    }

    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            solveNQueens(col + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    solveNQueens(0);
    cout << "Total solutions: " << Count << endl;
    return 0;
}

