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
	int** arr = new int* [N];
	for (int i(0); i < N; i++)
	{
		arr[i] = new int[N];
	}

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
	for (int i(0); i < N; i++)
	{
		for (int j(0); j < B; j++)
		{
			if ((arr[i][j] < arr[abs(i - 1)][j]) && (arr[i][j] < arr[((i + 1) == N ? i : i + 1)][j]) &&
				(arr[i][j] < arr[i][((j + 1) == B ? j : j + 1)]) && (arr[i][j] < arr[i][abs(j - 1)]) &&
				(arr[i][j] < arr[((i + 1) == N ? i : i + 1)][abs(j - 1)]) && (arr[i][j] < arr[((i + 1) == N ? i : i + 1)][((j + 1) == B ? j : j + 1)]) &&
				(arr[i][j] < arr[abs(i - 1)][abs(j - 1)]) && (arr[i][j] < arr[abs(i - 1)][((j + 1) == B ? j : j + 1)])) ind++;
		}
	}
	cout << "Количество локальных минимумов: " << ind;
	{
	for (int i(0); i < N; i++)
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}