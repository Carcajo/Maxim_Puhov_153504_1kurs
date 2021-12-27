#include <iostream>
#include "lib.h"
using namespace std;
void cout_m(int** a, int x) {
    for (int i(0); i < x; i++) {
        for (int j(0); j < x; j++)
            cout << a[i][j] << ' ';
        cout << "\n";;
    }
    cout << "\n";
}

void shet_m(int** a, int x) {
    for (int i(1); i <= x; i++)
    {
        for (int j(1); j <= x; j++)
        {
            if (i <= 5)
            {
                a[i - 1][j - 1] = 2 * i * j * j - 2 * j;
            }
            else
            {
                a[i - 1][j - 1] = 3 * i * j - 3;
            }
        }
    }
}
