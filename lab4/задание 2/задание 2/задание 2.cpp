#include <iostream>
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
	setlocale(LC_ALL,"Russian");
	int arr[5][5], a = 5, b = 5, max;

	for (int i(0); i < a; i++)
	{
		for (int j(0); j < b; j++)
		{
			cout << "Введите arr[" << i + 1 << "][" << j + 1 << "]";
			read(arr[i][j]);
		}
	}
	cout << "Исходный массив:\n";
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < b; j++)
		{
			cout << arr[i][j] << ' ';	
		}
		cout << endl;
	}
	max = arr[0][0];
	for (int i(0); i < a; i++)
	{
		for (int j(0); j < b; j++)
		{
			if ((i + j) < a - 1)
			{
				if (arr[i][j] > max) max = arr[i][j];
			}
		}
	}
	cout << "Максимальное значение: " << max;
	return 0;
}