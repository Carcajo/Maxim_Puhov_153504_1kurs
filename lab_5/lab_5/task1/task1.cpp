#include<iostream>
#pragma comment( lib, "lib.lib")
#include "lib.h"
using namespace std;

int main()
{
    const int k = 10;
    setlocale(LC_ALL, "Russian");
    
    int** arr = new int* [k];
    for (int i(0); i < k; i++)
    {
        arr[i] = new int[k];
    }
    
    shet_m(arr, k);

    cout_m(arr, k);
     
    int** arr2 = new int* [k];
    for (int j(0); j < k; j++)
    {
        arr2[j] = new int[k];
    }
   
    for (int i(0); i < k; i++)
    {
        for (int j(0); j < k; j++)
            arr2[j][i] = arr[i][j];
    }
    cout_m(arr2, k);

    int sum1 = 0, sum2 = 0;
    for (int i(0); i < k; i++)
        for (int j(0); j < k; j++) {
            if ((i + 1) % 2 == 0 && (j + 1) % 2 == 1)
                sum1 += arr[i][j];
            else if ((i + 1) % 2 == 1 && (j + 1) % 2 == 0)
                sum2 += arr2[i][j];
        }
    cout << sum1<<"\n" << sum2;

    for (int i(1); i < k; i++)
    {
        delete[] arr[i];
        delete[] arr2[i];
    }
    delete[] arr;
    delete[] arr2;
    return 0;

}