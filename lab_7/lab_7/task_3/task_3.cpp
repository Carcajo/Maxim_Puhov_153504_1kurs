/*Лабораторная работа №7, задание 3, вариант 5. Выполнил Пухов М.Ю.

Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.. Найдите сумму двоичных чисел, заданных в естественной 
форме. Сложение выполните в дополнительном коде. Ответ 
выразите в прямом коде. */

#include <iostream>		
using namespace std;

int findSt(int a)
{
	int ret = 0;
	while (a > 1)
	{
		a >>= 1;
		ret++;
	}
	return ret;
}

string findDop(string prkod)
{
	string obrkod = "", dopkod = "";
	for (int i = 0; i < prkod.length(); i++)
		if (prkod[i] == '1')
			obrkod += '0';
		else
			obrkod += '1';
	dopkod = obrkod;
	for (int i = obrkod.length() - 1; i >= 0; i--)
	{
		if (obrkod[i] == '0')
		{
			dopkod[i] = '1';
			break;
		}
		else
			dopkod[i] = '0';
	}
	return dopkod;
}

string findPr(string dopkod)
{
	string obrkod = dopkod;
	for (int i = obrkod.length() - 1; i >= 0; i--)
		if (obrkod[i] == '0')
			obrkod[i] = '1';
		else
		{
			obrkod[i] = '0';
			break;
		}
	string prkod = "";
	for (int i = 0; i < obrkod.length(); i++)
		if (obrkod[i] == '1')
			prkod += '0';
		else
			prkod += '1';
	return prkod;
}

char pl(char a, char b, char& c)
{
	int k = 0;
	if (a == '1')
		k++;
	if (b == '1')
		k++;
	if (c == '1')
		k++;
	if (k > 1)
		c = '1';
	else
		c = '0';
	if (k % 2 == 1)
		return '1';
	else
		return '0';
}

string intToPr(int a, char& v)
{
	string s;
	v = '0';
	if (a < 0)
	{
		v = '1';
		a *= -1;
	}
	int st = findSt(a);
	int b = pow(2, st);
	while (st >= 0)
	{
		if (a / b == 1)
		{
			a %= b;
			s += '1';
		}
		else
			s += '0';
		b >>= 1;
		st--;
	}
	return s;
}

int main()
{
	int fir, sec;
	cin >> fir;
	cin >> sec;
	string a, b;
	char va, vb;
	a = intToPr(fir, va);
	b = intToPr(sec, vb);
	while (a.length() < b.length())
		a = '0' + a;
	while (b.length() < a.length())
		b = '0' + b;
	string dopa = a;
	string dopb = b;
	if (va == '1')
		dopa = findDop(a);
	if (vb == '1')
		dopb = findDop(b);
	cout << va << ',' << a << endl;
	cout << va << ',' << dopa << endl;
	cout << vb << ',' << b << endl;
	cout << vb << ',' << dopb << endl;
	string res = dopa;
	char s = '0';
	for (int i = res.length(); i >= 0; i--)
		res[i] = pl(res[i], dopb[i], s);
	char vr = pl(va, vb, s);
	cout << vr << ',' << res << endl;
	string prres = res;
	if (vr == '1')
		prres = findPr(res);
	cout << vr << ',' << prres << endl;
}
