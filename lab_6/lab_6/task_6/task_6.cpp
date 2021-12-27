#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long Fact(int N)
{
    if (N == 1)
        return 1;
    else
        return N * Fact(N - 1);
}

int main()
{
    string str;
    long long x, y, p;
    cout << "set word: ";
    getline(std::cin, str);
    sort(str.begin(), str.end());
    x = y = 0;
    p = 1;
    for (int i = y; str[i]; i++)
    {
        if (str[i] == str[i + 1])
        {
            x++;
        }
        else
        {
            y = x;
            x++;
            p *= Fact(x);
            x = 0;
        }
    }
    cout << Fact(str.size()) / p << endl;
    return 0;
}