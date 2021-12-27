<<<<<<< HEAD
﻿#include <iostream>
=======
#include <iostream>
>>>>>>> f5bbb44505ed9c1c6a1b3198595284a844b50688
#include <malloc.h>

using namespace std;

int main()                        // Магический квадрат начинается с 3
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    cout << "Введите размер квадрата: ";
    cin >> size;

    if (!(size & 1)) {
        cout << "Размер имеет значение. Введите нечетное целое число";
        cin.get();
        return(1);
    }

    int max_size = size + (size - 1);

    int* Magic_square = (int*)malloc(max_size * max_size * 4);


    int i;
    int j;
    for (i = 0; i < max_size; i++)
        for (j = 0; j < max_size; j++)
            Magic_square[i * max_size + j] = 0;
    int k = 1;
    i = (max_size >> 1);
    j = 0;
    while (i < max_size) {
        int i1 = i;
        int j1 = j;
        int gr = size >> 1; //gr-расстояние от границы увеличенного массива
        while (j1 < ((j + (max_size >> 1)) + 1)) {
            Magic_square[i1 * max_size + j1] = k;
            if ((i1 > (gr)) && (j1 < (gr))) //левая грань
                Magic_square[i1 * max_size + j1 + size] = k;
            if ((i1 > (size + gr) - 1) && (j1 > (gr)))
                Magic_square[(i1 - size) * max_size + j1] = k; //нижняя грань
            if ((i1 < (gr)) && (j1 > (gr)))
                Magic_square[(i1 + size) * max_size + j1] = k; //верхняя грань
            if ((i1 > (gr)) && (j1 > (size + gr) - 1))
                Magic_square[i1 * max_size + j1 - size] = k; //правая грань
            --i1;
            ++j1;
            ++k;
        }
        ++i;
        ++j;
    }
    cout << endl << "Магический квадрат: " << endl << endl;
    int a = (size >> 1) * max_size;   //размер верхней грани
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            cout << Magic_square[a + (size >> 1) + i * (size - 1) + i * size + j] << " ";  // size >> 1 - элементы слева, i * (size - 1) - элементы слева и справа строк выше i * size - элементы, которые мы вывели раньше
        cout << endl;
    }
    /*for (int i = 0; i < max_size; ++i)
        delete[] Magic_square[i];
    delete[] Magic_square;*/
    free(Magic_square);

    cin.get();
    return 0;
}
