#include <iostream>
using namespace std;

int main()
{
	int time, n, bochk;
	cout << "Time of death(minutes):";
	cin >> time;
	cout << "Death slave:";
	cin >> n;
	switch(n)
	{case 1:
		time /= 30;
		bochk = time;
		cout << bochk;
		break;
	case 2:
		time /= 30;
		bochk = time+48;
		cout << bochk;
		break;
	case 3:
		time /= 30;
		bochk = time+96;
		cout << bochk;
		break;
	case 4:
		time /= 30;
		bochk = time+144;
		cout << bochk;
		break;
	case 5:
		time /= 30;
		bochk = time+192;
		cout << bochk;
		break;
	}
	return 0;
}