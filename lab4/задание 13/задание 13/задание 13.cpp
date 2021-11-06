#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a,r=1;
	cout << "Введите количество удлинителей:";
	cin >> a;
	for (int i= 1; i <= a; i++)
	{
		r += i - 1;
	}
	cout << "Число розеток" << r;
	return 0;
}