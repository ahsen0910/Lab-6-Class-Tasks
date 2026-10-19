#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {0, 0, 1, 1}
};

int path[N][N] = {0};
int Count = 0;

bool isSafe(int row, int col)
{
    if (row < 0 || row >= N || col < 0 || col >= N)
        return false;

    if (maze[row][col] == 0 || path[row][col] == 1)
        return false;

    return true;
}

void printPath()
{
    Count++;

    cout << "Solution " << Count << ":" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << path[i][j] << " ";

        cout << endl;
    }

    cout << endl;
}

void solveMaze(int row, int col)
{
    if (row == N - 1 && col == N - 1)
    {
        path[row][col] = 1;
        printPath();
        path[row][col] = 0;
        return;
    }

    if (isSafe(row, col) == true)
    {
        path[row][col] = 1;

        solveMaze(row, col + 1);
        solveMaze(row + 1, col);
        solveMaze(row, col - 1);
        solveMaze(row - 1, col);

        path[row][col] = 0;
    }
}

int main()
{
    if (maze[0][0] == 1)
        solveMaze(0, 0);

    if (Count == 0)
        cout << "No solution exists";
    else
        cout << "Total solutions: " << Count;

    return 0;
}
