#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter N=";
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	HINSTANCE load;
	load = LoadLibrary(L"tasssk2.dll");
	typedef double(__stdcall* fuck)(int*, int, int);
	fuck Fuck = (fuck)GetProcAddress(load, "Fuck");

	double r = Fuck(arr, 0, n / 3) * Fuck(arr, n / 3, n);
	cout << "result" << r;

	FreeLibrary(load);
}