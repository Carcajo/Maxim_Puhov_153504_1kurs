/*Лабораторная работа №5, задание 3.3. Выполнил Пухов М.Ю.
Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.
*/

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

void cout_m(int** a, int x) {
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

    int  M, ** arr, * arr2;
    double sum(0);
    //Проверка на N и M
    cout << "Создаём матрицу N*M \n";

    do
    {
        cout << "Введите M в диапазоне от 1 до 25:\n";
        read(M);
    } while (M < 1 || M > 25);
    //Создание двумерных массивов
    arr = new int* [M];
    for (int i(0); i < M; i++)
        arr[i] = new int[M];

    arr2 = new int[M * M];
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
    cout_m(arr,M);

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

