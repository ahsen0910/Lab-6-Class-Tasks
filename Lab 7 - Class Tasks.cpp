#include <iostream>
using namespace std;

void Merge(int Arr[], int Left, int Mid, int Right)
{
    int N1 = Mid - Left + 1;
    int N2 = Right - Mid;

    int* A = new int[N1];
    int* B = new int[N2];

    for (int I = 0; I < N1; I++)
        A[I] = Arr[Left + I];

    for (int I = 0; I < N2; I++)
        B[I] = Arr[Mid + 1 + I];

    int I = 0, J = 0, K = Left; 

    while (I < N1 && J < N2)
    {
        if (A[I] <= B[J])
            Arr[K++] = A[I++];
        else
            Arr[K++] = B[J++];
    }

    while (I < N1)
        Arr[K++] = A[I++];

    while (J < N2)
        Arr[K++] = B[J++];

    delete[] A;
    delete[] B;
}

void MergeSort(int Arr[], int Left, int Right)
{
    if (Left >= Right)
        return;

    int Mid = Left + (Right - Left) / 2;

    MergeSort(Arr, Left, Mid);
    MergeSort(Arr, Mid + 1, Right);

    Merge(Arr, Left, Mid, Right);
}

int main()
{
    int Arr[] = {38, 12, 27, 43, 9, 31, 18, 25};
    int N = sizeof(Arr) / sizeof(Arr[0]);

    MergeSort(Arr, 0, N - 1);

    for (int I = 0; I < N; I++)
        cout << Arr[I] << " ";

    return 0;
}
