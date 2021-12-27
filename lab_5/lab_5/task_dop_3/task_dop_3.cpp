#include<iostream>
using namespace std;

int  del_m(int n)
{
	if (n % 2 == 0)
	{
		n = del_m(n/2);
	}
	return n;
}

int sum_m(int n)
{
	if (n == 0) return 0;
	int del = del_m(n);
	n--;
	del += sum_m(n);
	return del;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, rez;
	while (true)
	{
		cout << "Введите число \n";
		cin >> n;
		rez = sum_m(n);
		cout <<"Результат\n" <<rez << "\n";
	}
	return 0;
}