/*Лабораторная работа №5, задание dop_1. Выполнил Пухов М.Ю.
По заданным p и q необходимо вычислить S (p, q).
*/

#include <iostream>
#include <cmath>

using namespace std;
int fun(int n)
{
	if (n % 10 > 0)
		return n%10;
	else if (n==0)
		return 0;
	else
		return fun(n / 10);
	
}

int s(int p, int q)
{
	int sum = 0;
	for ( int i=p; i<=q; i++)
	{
		sum += fun(i);
	}
	return sum;
}

int main()
{
		int p, q, n;
		cout << "Enter p,q";
		while (cin >> p >> q)
	{
		if (p == -1 && q == -1)
			break;
		cout << s(p, q);
		cout << "Enter p,q";
	}
}
