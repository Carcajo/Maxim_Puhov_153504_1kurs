#include <iostream> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int N, M, count, temp;

    cout << "Введите размер матрицы NxM: ";
    cin >> N >> M;

    int** arr = new int* [N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = rand() % 10 + 1;
        }
    }

    temp = arr[0][0];

    cout << "\n\nПервоначальная матрица:\n\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n\n";
    }

    for (int count = 0; count < N * M; count++)
    {
        for (int i = 0; (i <= count / M); i++)
        {
            for (int j = 0; (j <= count % M); j++)
            {
                if (arr[i][j] > temp)
                {
                    temp = arr[i][j];
                }
            }
        }
        arr[count / M][count % M] = temp;

        temp = arr[0][0];
    }

    cout << "\n\nИсходная матрица:\n\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n\n";
    }

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}