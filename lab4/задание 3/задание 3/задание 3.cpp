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
void clean(int N, int** arr)
{
	for (int i(0); i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, sum(0), p(0);

	cout << "Введите размер квадратной матрицы: ";
	do  read(N);  while (N < 2);

	int** arr = new int* [N];
	for (int i(0); i < N; i++)
	{
		arr[i] = new int[N];
	}

	for (int i(0); i < N; i++)
	{
		for (int j(0); j < N; j++)
		{
			cout << "Введите элемент матрицы [" << i + 1 << "][" << j + 1 << "]: ";
			read(arr[i][j]);
		}
	}

	for (int i(0); i < 1; i++)
	{
		for (int j(0);j < N; j++)
		{
			sum += arr[i][j];
		}
	}

	for (int i(0); i < N; i++)
	{
		for (int j(0); j < N; j++)
		{
			p += arr[i][j];
		}
		if (p == sum)
		{
			p = 0;
		}
		else
		{
			cout << "Квадрат не является магческим.";
			clean(N, arr);
			return 0;
		}
	}
	for (int i(0); i < N; i++)
	{
		for (int j(0); j < N; j++)
		{
			p += arr[j][i];
		}
		if ((i == N - 1) && (sum == p))
		{
			cout << "Квадрат является магическим!";
			clean(N, arr);
			return 0;
		}
		if (p == sum)
		{
			p = 0;
		}
		else
		{
			cout << "Квадрат не является магческим.";
			clean(N, arr);
			return 0;
		}
	}
	return 0;
}