/*Лабораторная работа №7, задание 5, вариант 5. Выполнил Пухов М.Ю.
 Перевести число из арабской системы записи чисел в римскую.*/

#include <iostream>
#include <string>
using namespace std;

int input(int min, int max) {
	int text;
	while (true)
	{
		cin >> text;
		if (text < max && text > min)
			return text;
		cin.clear();
		cin.ignore(32672, '\n');
		cout << "Enter correct word" << endl;
	}
}

string imagine(int number) {
	string num;
	string* units = new string[]{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
	for (int i = 0; i < number / 1000; i++)
	{
		num.push_back('M');
	}
	number %= 1000;
	if ((number % 500) / 100 + 5 == 9)
	{
		num += "CM";
		number %= 900;
	}
	else if (number / 500 > 0)
	{
		num.push_back('D');
		number %= 500;
	}
	for (int i = 0; i < number / 100; i++)
	{
		num.push_back('C');
	}
	number %= 100;


	if ((number % 50) / 10 + 5 == 9)
	{
		num += "XC";
		number %= 90;
	}
	else if (number / 50 > 0)
	{
		num.push_back('L');
		number %= 50;
	}
	if (number % 10 == 4)
	{
		num += "XL";
		number %= 40;
	}

	for (int i = 0; i < number / 10; i++)
	{
		num.push_back('X');
	}
	number %= 10;
	num += units[number];
	return num;
}
int main()
{
	cout << imagine(input(0, 4000));
}
