#include <iostream>
using namespace std;

int inputArrInt(long long int i2, long long int j2)
{
    double value;

    cin >> value;

    while (cin.fail() || value != (int)value) {
        cout << "Ввод некорректен. Введите элемент [" << i2 + 1 << ", " << j2 + 1 << "] заново:\n";

        cin.clear();
        cin.ignore(3256, '\n');

        cin >> value;
    }

    return value;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    long long int n, m, k;

    int** arr1;
    int** arr2;
    int** arr3;

    cout << "Будет объявлено два двумерных массива m x n и n x k соответственно. Для введённый матриц будет высчитано их произведение.\n\nВведите m, n и k: ";

    cin >> m >> n >> k;

    while (cin.peek() == ' ')
        cin.ignore(1, ' ');

    while (cin.fail() || cin.peek() != '\n' || k <= 0 || n <= 0 || m <= 0 || n != (long long int)n || m != (long long int)m || k != (long long int)k) {
        cout << "Ввод некорректен. Введите заново n, m и k (целые положительные числовые значение): ";

        cin.clear();
        cin.ignore(3256, '\n');

        cin >> m >> n >> k;
        while (cin.peek() == ' ')
            cin.ignore(1, ' ');
    }

    cout << '\n';

    arr1 = (int**)malloc(m * sizeof(int*));
    arr2 = (int**)malloc(n * sizeof(int*));
    arr3 = (int**)malloc(m * sizeof(int*));

    for (long long int i = 0; i < m; ++i) {
        arr1[i] = (int*)malloc(n * sizeof(int));
    }
    for (long long int i = 0; i < n; ++i) {
        arr2[i] = (int*)malloc(k * sizeof(int));
    }
    for (long long int i = 0; i < m; ++i) {
        arr3[i] = (int*)malloc(k * sizeof(int));
    }

    cout << "Введите элементы первого массива (" << m << " x " << n << "):\n";
    for (long long int i = 0; i < m; ++i) {
        for (long long int j = 0; j < n; ++j) {
            arr1[i][j] = inputArrInt(i, j);
        }
    }

    cout << "\nВведите элементы второго массива (" << n << " x " << k << "):\n";
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < k; ++j) {
            arr2[i][j] = inputArrInt(i, j);
        }
    }

    // Алгоритм перемножения матриц
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int r = 0; r < n; ++r) {
                arr3[i][j] += arr1[i][r] * arr2[r][j];
            }
        }
    }

    cout << "\nПеремножение двух матриц равно:\n\n";

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << arr3[i][j] << "  ";
        }
        cout << '\n';
    }

    for (long long int i = 0; i < m; ++i) {
        free(arr1[i]);
    }
    free(arr1);

    for (long long int i = 0; i < n; ++i) {
        free(arr2[i]);
    }
    free(arr2);

    for (long long int i = 0; i < m; ++i) {
        free(arr3[i]);
    }
    free(arr3);

    return 0;
}