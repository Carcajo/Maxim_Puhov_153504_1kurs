/*Лабораторная работа №5, задание 3.1. Выполнил Пухов М.Ю.
Дан двумерный динамический массив целых чисел А размерностью n  k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. Вычислить произведение
элементов динамического массива.
Созданный массив и результат произведения вывести на экран.
Использовать функции.*/

#include <iostream>

using namespace std;

void read(int& a)
{
    while (true)
    {
        cin >> a;
        if (cin.fail() || cin.peek() != '\n')
        {
            cout << "Ошибка! Неверный ввод\n";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int N, M, ** arr, t(0), * arr2;
    long long int pr(1);
    //Проверка на N и M
    cout << "Создаём матрицу N*M \n";
    do
    {
        cout << "Введите N в диапозоне от 1 до 25:\n";
        read(N);
    } while (N < 1 || N > 25);

    do
    {
        cout << "Введите M в диапазоне от 1 до 25:\n";
        read(M);
    } while (M < 1 || M > 25);
    //Создание двумерного массива
    arr = new int* [N];
    for (int i(0); i < N; i++)
    {
        arr[i] = new int[M];
    }
    arr2 = new int[N];
    for (int i(0); i < N; i++)
        arr2[i] = 0;

    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
        {
            cout << "Элемнет arr[" << i << "][" << j << "] равен: ";
            read(arr[i][j]);
        }
    }


    cout << "Исходная матрица равна: " << endl;
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    //Начало алгоритма
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
        {
            pr *= arr[i][j];
            if (i == j && arr[i][j] % 2 == 0)
            {
                arr2[t] = arr[i][j];
                t++;
            }

        }
    }


    cout << "Подходящаие эленты: ";
    for (int i(0); arr2[i]; i++)
        cout << arr2[i] << ' ';
    cout << "\nПроизведение: " << pr << endl;

    delete[] arr2;
    for (int i(0); i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
