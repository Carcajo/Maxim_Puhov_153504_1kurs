#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a1[10], a2[10]{ 0,0,0,0,0,0,0,0,0,0 }, a3[10] = { 0,0,0,0,0,0,0,0,0,0 }, a(10);
	cout << "Заполняем массив:" << endl;
	for (int i(0); i < a; i++)
	{
		cout << "Введите " << i + 1 << " элемент: ";
		cin >> a1[i];
	}
	for (int i(0); i < a; i++)
	{
		if (a1[i] < 0) a2[i] = a1[i];
		else a3[i] = a1[i];
	}
	cout << "Отрицательный массив: " << endl;
	for (int i(0); i < a; i++)
	{
		if (a2[i]) cout << a2[i] << ' ';
	}
	cout << "\nПоложительный массив: " << endl;
	for (int i(0); i < a; i++)
	{
		if (a3[i]) cout << a3[i] << ' ';
	}
	return 0;
}