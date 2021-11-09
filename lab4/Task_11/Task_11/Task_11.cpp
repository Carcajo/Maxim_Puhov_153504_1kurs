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

int main() {
    int N;
    N = int(input());

    auto a = (int***)malloc(N * sizeof(int**));
    for (int i = 0; i < N; i++) {
        a[i] = (int**)malloc(N * sizeof(int*));
        for (int j = 0; j < N; j++) {
            a[i][j] = (int*)malloc(N * sizeof(int));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int z = 0; z < N; z++) {
                a[i][j][z] = int(input());
            }
        }
    }

    int sum_m = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum_m += a[i][i][i];
    }

    for (int i = N - 1; i >= 0; i--) {
        sum += a[N - (1 + i)][i][N - (1 + i)];
    }

    sum_m = sum_m > sum ? sum_m : sum;
    sum = 0;

    for (int i = 0; i < N; i++) {
        sum += a[i][i][N - (1 + i)];
    }

    sum_m = sum_m > sum ? sum_m : sum;
    sum = 0;

    for (int i = N - 1; i >= 0; i--) {

        sum += a[N - (1 + i)][i][i];
    }

    sum_m = sum_m > sum ? sum_m : sum;

    cout << "Max sum: " << sum_m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    return 0;
}