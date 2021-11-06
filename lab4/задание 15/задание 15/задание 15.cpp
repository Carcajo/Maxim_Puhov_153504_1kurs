#include <iostream>
using namespace std;

double input() {
    string s;
    cin >> s;
    int c_dot = 0, c_e = 0, c_c = 0, inv = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '+': {
            c_c++;
            if (i > 1 && ((s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '.')
                || (s[i + 1] == '-' || s[i + 1] == '+' || s[i + 1] == '.') || s[i - 1] != 'e' || s[i + 1] == 'e')) {
                inv = 1;
            }
            break;
        }
        case '-': {
            c_c++;
            if (i > 1 && ((s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '.')
                || (s[i + 1] == '-' || s[i + 1] == '+' || s[i + 1] == '.') || s[i - 1] != 'e' || s[i + 1] == 'e')) {
                inv = 1;
            }
            break;
        }
        case 'e': {
            c_e++;
            if (i > 1 && (s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '.'
                || s[i] == '.' || s[i + 1] == 'e')) {
                inv = 1;
            }
            break;
        }
        case '.': {
            c_dot++;
            break;
        }
        default:
            if (int(s[i]) < 48 || int(s[i]) > 57) {
                inv = 1;
            }
        }

        if (c_e >= 2 || c_dot >= 1 || (s[s.length() - 1] == 'e' || s[0] == 'e') || (s[s.length() - 1] == '-' && s.length() != 2) || s[s.length() - 1] == '+' || (c_e != 1 && c_c >= 2)) {
            inv = 1;
        }

        if (inv) {
            cout << "Incorrect input. Try again:\n";
            c_dot = 0, c_e = 0, c_c = 0, inv = 0;
            cin >> s;
            i = 0;
        }
    }
    return strtod(s.c_str(), nullptr);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    long long int c = 1, k;

    cout << "Введите число, позицию которого хотите найти в таблице:\n";
    k = int(input());

    int i = 1, stolbets = 1, stroka = 1, z = 2;
    if (k == 1) cout << "В строке 1, столбце 1" << endl;
    else {
        while (z) {
            stolbets = z;
            for (; stroka < z; stroka++)
            {
                i++;
                if (i == k) {
                    cout << "В в строке " << stroka << ", столбце " << stolbets << endl;
                    z -= (z + 1);
                }
            }
            for (; stolbets > 0; stolbets--)
            {
                i++;
                if (i == k) {
                    cout << "В строке " << stroka << ", столбце " << stolbets << endl;
                    z -= (z + 1);
                }
            }
            stroka = 1;
            z++;
        }
    }

    return 0;
}