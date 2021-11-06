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
	setlocale(LC_ALL, "Russian");
	int N, B, ind(0);
	cout << "Введите количество строк: ";
	do  read(N);  while (N < 1);
	cout << "Введите количество сстолбцов: ";
	do  read(B);  while (B < 1);
	double** ans = new double* [N];
	for (int i(0); i < N; i++)
		ans[i] = new double[B];
	int** arr = new int* [N];
	for (int i(0); i < N; i++)
		arr[i] = new int[N];

	for (int i(0); i < N; i++)
	{
		for (int j(0); j < B; j++)
		{
			cout << "Введите элемент матрицы [" << i + 1 << "][" << j + 1 << "]: ";
			read(arr[i][j]);
		}
	}
	cout << "Массив:\n";
	for (int i(0); i < N; i++)
	{
		for (int j(0); j < B; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout.precision(5);
	cout << fixed;
	cout << "Новый массив:\n";
	for (int i(0); i < N; i++)
	{
		for (int j(0); j < B; j++)
		{
			double sum = arr[abs(i - 1)][abs(j - 1)] + arr[abs(i - 1)][j] + arr[abs(i - 1)][((j + 1) == B ? j : j + 1)] +
				arr[i][abs(j - 1)] + arr[i][((j + 1) == B ? j : j + 1)] + arr[((i + 1) == N ? i : i + 1)][abs(j - 1)] +
				arr[((i + 1) == N ? i : i + 1)][j] + arr[((i + 1) == N ? i : i + 1)][((j + 1) == B ? j : j + 1)];
			double d = 8;
			if ((i == 0 || i == N - 1) && (j == 0 || j == B - 1))
			{
				sum -= 2 * arr[abs(i - 1)][abs(j - 1)];
				d = 6;
			}
			else
				if (i == 0 || i == N - 1)
				{
					sum += arr[i][j - 1] + arr[i][j + 1];
					d = 10;
				}
				else
					if (j == 0 || j == B - 1)
					{
						sum += arr[i - 1][j] + arr[i + 1][j];
						d = 10;
					}
			ans[i][j] = (double)(sum / d);
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	for (int i(0); i < N; i++)
		delete[] ans[i];
	delete[] ans;
	for (int i(0); i < N; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}