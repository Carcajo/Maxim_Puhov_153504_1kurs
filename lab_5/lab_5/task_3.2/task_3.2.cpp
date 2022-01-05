/*Лабораторная работа №5, задание 3.2. Выполнил Пухов М.Ю.
Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include <iostream>

using namespace std;

char read(double& a)
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

void cout_m(double** a, int x) {
    for (int i(0); i < x; i++) {
        for (int j(0); j < x; j++)
            cout << a[i][j] << ' ';
        cout << "\n";;
    }
    cout << "\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    double  M, ** arr, * arr2;
    double sum(0);
    //Проверка на N и M
    cout << "Создаём матрицу N*M \n";

    do
    {
        cout << "Введите M в диапазоне от 1 до 25:\n";
        read(M);
    } while (M < 1 || M > 25);
    //Создание двумерных массивов
    arr = new double* [M];
    for (int i(0); i < M; i++)
        arr[i] = new double[M];

    arr2 = new double[M * M];
    for (int i(0); i < M * M; i++)
    {
        arr2[i] = 0;
    }
    // ввод значений
    for (int i(0); i < M; i++)
    {
        for (int j(0); j < M; j++)
        {
            cout << "Элемнет arr[" << i << "][" << j << "] равен: ";
            read(arr[i][j]);
        }
    }

    //вывод матрицы

    cout << "Исходная матрица равна:" << endl;
    cout_m(arr, M);

    //Начало алгоритма

    int k = 0;
    for (int i(0); i < M; i++)
    {
        for (int j(0); j < M; j++)
        {
            sum += arr[i][j];
            if ((j % 2 == 1) && (arr[i][j] % 2 == 1) && (arr[i][j] != 0))
            {
                arr2[k] = arr[i][j];
                k++;
            }
        }
    }

    cout << endl << endl << endl << "Подходящаие эленты: ";
    for (int i(0); arr2[i]; i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << "\nСреднее арифметическое: " << sum / (M * M) << endl;


    delete[] arr2;
    for (int i(0); i < M; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
/*
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double* x = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    delete[]x;
    return 0;
}*/

