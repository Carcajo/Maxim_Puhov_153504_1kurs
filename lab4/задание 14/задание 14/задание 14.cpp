#include <stdlib.h> 
#include <iostream> 
#include <time.h> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int rows, colums, bomb, bombs = 0, k, g;
    cout << "Введите высоту n и длину m поля\n";
    while (!(cin >> rows) || rows <= 1 || rows != round(rows))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректное значение\n";
    }
    while (!(cin >> colums) || colums <= 1 || colums != round(colums))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректное значение\n";
    }
    char** arr = (char**)calloc(rows, sizeof(char*));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (char*)calloc(colums, sizeof(char));
    }
    cout << "Введите количество бомб\n";
    while (!(cin >> bomb) || bomb < 1 || bomb != round(bomb) || bomb >= rows * colums / 2)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите корректное значение\n";
    }
    srand(time(0));
    while (bomb != 0)
    {
        int i = rand() % (rows - 1);
        int j = rand() % (colums - 1);
        if (arr[i][j] != '*')
        {
            arr[i][j] = '*';
            --bomb;
        }
    }
    cout << "Промежуточный вариант:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            if (arr[i][j] != '*')
            {
                arr[i][j] = '.';
            }
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            if (arr[i][j] != '*')
            {
                k = i - 1;
                g = j - 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i - 1;
                g = j;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i - 1;
                g = j + 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i;
                g = j + 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i + 1;
                g = j + 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i + 1;
                g = j;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i + 1;
                g = j - 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                k = i;
                g = j - 1;
                if (k >= 0 && g >= 0 && k < rows && g < colums)
                    if (arr[k][g] == '*')
                        bombs += 1;
                arr[i][j] = bombs + 48;
                bombs = 0;
            }
        }
    }
    cout << "Конечное поле\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }




    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}