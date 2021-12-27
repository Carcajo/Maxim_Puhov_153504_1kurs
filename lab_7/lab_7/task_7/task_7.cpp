#include<iostream>
using namespace std;

int main() {
    int num, k = 0;
    cout << "set num: "; cin >> num;
    for (int i = 0; i <= num; i += 5) {
        if (i == num)
            k = 1;
    }
    if (k == 1)
        cout << "\ndel na 5";
    else
        cout << "\nne del na 5";

    k = 0;
    for (int i = 0; i <= num; i += 73) {
        if (i == num)
            k = 1;
    }
    if (k == 1)
        cout << "\ndel na 73";
    else
        cout << "\nne del na 73";

    k = 0;
    for (int i = 0; i <= num; i += 151) {
        if (i == num)
            k = 1;
    }
    if (k == 1)
        cout << "\ndel na 151";
    else
        cout << "\nne del na 151";
}