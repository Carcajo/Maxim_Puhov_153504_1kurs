/*Лабораторная работа №7, задание 6, вариант 5. Выполнил Пухов М.Ю.
 Подсчитать количество X,если оно является "интересным".*/

#include<iostream>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        cout << (x + 1) / 10 << endl;
    }
}
    
