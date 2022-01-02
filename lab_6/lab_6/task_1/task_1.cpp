/*Лабораторная работа №6, задание 1, вариант 5. Выполнил Пухов М.Ю.

 В строке, состоящей из групп нулей и единиц, подсчитать 
количество единиц в группах с нечетным количеством символов.*/

#include<iostream>
#include <string>
using namespace std;

bool RightNumber(const char* str) {
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == ' ')
			continue;
		else
			return false;
	}
	return true;
}

void Count_m(char* str)
{
	int size = strlen(str);
	int i = 0;
	while (i < size)
	{
		int length = 0, kol = 0;
		while (i < size && str[i] != ' ')
		{
			if (str[i] == '1')
			kol++;
			i++;
			length++;
		}
		while (i < size && str[i] == ' ')
			i++;
		if (length % 2 == 1)
			cout << kol << endl;
	}
}

int main()
{
	const int size=80;
	char str[size];

	while (true)
	{
		cin.getline(str, 80);
		if (RightNumber(str))
			break;
		cin.ignore(32764, '\n');
		cout << "Incorrect enter.Try again" << endl;
	}
	Count_m(str);
}
