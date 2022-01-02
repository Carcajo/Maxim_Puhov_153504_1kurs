/*Лабораторная работа №7, задание 2, вариант 5. Выполнил Пухов М.Ю.

Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.Из прямого кода в дополнительный*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[100];
	char str1[100];
	gets_s(str);
	int n = strlen(str);
    for (int i = 1; i < n; i++)
    {
        str1[i] = str[i];
    }
    if (str[0] == '1')
    {
        for (int i = 1; i < n; i++)
        {
            if (str[i] == '0')
            {
                str[i] = '1';
            }
            else
            {
                str[i] = '0';
            }
        }
        if (str[n - 1] != '1')str[n - 1] = '1';
        else
        {
            for (int i = n - 1; i > 1; i--)
            {
                if (str[i] == '0' && str1[i] == '1')
                {
                    str[i] = '1';

                }
                if (str[i] == '1' && str1[i] == '0')
                {
                    str[i] = '0';

                }
            }
        }

    }        
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
	return 0;
}
