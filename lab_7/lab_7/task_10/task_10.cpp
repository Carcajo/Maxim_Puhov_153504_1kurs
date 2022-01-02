/*Лабораторная работа №7, задание 10, вариант 5. Выполнил Пухов М.Ю.

Патриций решил устроить праздник и для этого приготовил 240
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба
неизвестна. Про яд известно, что человек, который его выпил, умирает в
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в
какой именно бочке яд. Каким образом можно это узнать?*/

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
