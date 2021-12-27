#include <iostream>
#include <Windows.h>
using namespace std;
	
int main()
{
	int n;
	cout << "Enter N=";
	cin >> n;

	int* arr = new int [n];
	cout << "Enter elements";
	for (int i =0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	//HINSTANCE load;
	//load = LoadLibrary(L"DLL.dll");
	typedef double (*fuck)(int*, int, int);
	fuck Fuck = (fuck)GetProcAddress(LoadLibrary(L"DLL.dll"), "Fuck");

	double r = Fuck(arr, 0, n / 3) * Fuck(arr, n / 3, n);
	cout <<"result"<< r;

	//FreeLibrary(load);
}