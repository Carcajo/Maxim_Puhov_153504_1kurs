#include <iostream>
using namespace std;

int main()
{
	int n, avg = 0;
	cin >> n;
	char** arr = new char* [n];
	cin.ignore(32767, '\n');
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[256];
		cin.getline(arr[i], 256);
		int j = 0;
		while (arr[i][j] != '\0')
			j++;
		avg += j;
	}
	avg = round((double)avg / n);
	for (int i = 0; i < n; i++)
	{
		bool p = 0;
		for (int j = 0; j < avg; j++)
		{
			if (arr[i][j] == '\0')
				p = 1;
			if (p)
				arr[i][j] = ' ';
		}
		arr[i][avg] = '\0';
		cout << arr[i] << endl;
	}
	for (int i = 0; i < n; i++)
		delete[]arr[i];
	delete[]arr;
}