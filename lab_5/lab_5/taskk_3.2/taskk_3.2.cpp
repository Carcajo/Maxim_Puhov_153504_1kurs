#include<iostream>
using namespace std;
 
void printInd(double** a, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!a[i][j])
				cout << i + 1 << " " << j + 1 << endl;
}

void reverse(double**& a, int n, int m)
{
	double** b = new double* [n];
	for (int i = n - 1; i >= 0; i--)
	{
		b[n - i - 1] = new double[m];
		for (int j = m - 1; j >= 0; j--)
			b[n - i - 1][m - j - 1] = a[i][j];
		delete[] a[i];
	}
	delete[] a;
	a = b;
}

int main()
{
	double** a;
	int n, m, k = 0;
	cin >> n >> m;
	a = new double* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (!a[i][j])
				k++;
		}
	}
	if (k == 0)
		cout << "No 0 elements\n";
	else
	{
		cout << "There are " << k << " 0 elements:\n";
		printInd(a, n, m);
	}

	reverse(a, n, m);
	cout << fixed;
	cout.precision(5);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
		delete[] a[i];
	}
	delete[] a;
	return 0;
}