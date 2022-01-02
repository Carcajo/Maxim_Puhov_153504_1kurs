/*Лабораторная работа №7, задание 9, вариант 5. Выполнил Пухов М.Ю.

Вчера на уроке математики Саша (возможно Богом данный) узнал
о том, что иногда полезно использовать вместо десятичной системы
счисления какую-нибудь другую. Однако, учительница (как иронично) не
объяснила, почему в системе счисления по основанию b в качестве цифр
выбирают числа от 0 до b - 1. Немного подумав, Саша понял, что можно
выбирать и другие наборы цифр. Например, вместо троичной системы
счисления можно рассмотреть систему счисления, где вместо обычных цифр
0, 1, 2 есть цифры 1, 2 и 3. Саша заинтересовался вопросом, а как перевести
число n в эту систему счисления? Например, число 7 в этой системе
записывается как 21, так как 7 = 2∙3+1, а число 22 записывается как 211, так
как 22 = 2 ∙ 9 + 1 ∙ 3 + 1.*/

#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int TMP(int Value, int System) {
    int a = Value, t = 0, b;
    while (a > System - 1)
    {
        b = a % System;
        t++;
        a /= System;
    }
    t++;
    return t;
}
int SysConTo10(char str[], int sys)          // Функиция, переводящая в 10-ную систему счисления;
{
    double k, res = 0, st = 0, tmp = strlen(str);
    for (int i = tmp - 1; i >= 0; i--) {
        switch (str[i]) {
        case 'a': k = 10;
            break;
        case 'b': k = 11;
            break;
        case 'c': k = 12;
            break;
        case 'd': k = 13;
            break;
        case 'e': k = 14;
            break;
        case 'f': k = 15;
            break;
        default: k = (int)str[i];
            break;
        }
        if (k >= 48) {
            k -= 48;
        }
        if (k == 45) {
            break;
        }
        if (k >= sys) {
            cout << "Неправильно введены данные. Попробуй снова\n";
            break;
            return 0;
        }
        else if (k != sys) {
            res += pow(sys, st) * k;
            st++;
        }
    }
    return res;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int m, res = 0, st = 0; // m - основание системы счисления, res - результат, st - степень, val - строка в которую введено число;
    char val[100] = " ";
    cout << "Введите число: ";
    gets_s(val);
    int minus = 0;
    if (val[0] == 45) {
        minus = 1;
    }
    cout << "Из какой системы счисления переводите (число): ";
    cin >> m;
    int m2 = 0;
    cout << "В какую систему счисления вы хотите перевести число ?" << endl;
    res = SysConTo10(val, m);
    cin >> m2;
    int t2 = TMP(res, m2);
    for (int i = 0; i < t2; i++) {
        int b = res % m2;
        switch (b)
        {
        case 10: {
            val[i] = 'a';
            res /= m2;
        }
               break;
        case 11: {
            val[i] = 'b';
            res /= m2;
        }
               break;
        case 12: {
            val[i] = 'c';
            res /= m2;
        }
               break;
        case 13: {
            val[i] = 'd';
            res /= m2;
        }
               break;
        case 14: {
            val[i] = 'e';
            res /= m2;
        }
               break;
        case 15: {
            val[i] = 'f';
            res /= m2;
        }
               break;
        default: {
            if (b < 48) {
                b += 48;
            }
            val[i] = b;
            res /= m2;
        }
               break;
        }
    }
    if (minus == 1) {
        cout << "-";
        for (int i = t2 - 1; i > -1; i--)
            cout << val[i];
    }
    else {
        for (int i = t2 - 1; i > -1; i--)
            cout << val[i];
    }
    cout << endl;
}
