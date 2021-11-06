#include<iostream>
using namespace std;

void read(int& a)
{
	while (true)
	{
		cin >> a;
		if (cin.fail() || cin.peek() != '\n')
		{
			cout << "Ошибка! Неверный ввод\n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i,a,b, arr[5] = { 0,0,0,0,0 };
	cout << "Введите n: ";
	read(n);
	cout << "Введите i: ";
	read(i);

	for (int j = 0, a = 10000, b = 1; j < 5; j++, b *= 10)

	for (int j = 0; j < 5; j++)
	{
		cout << arr[j] << ' ';
	}



	return 0;
}