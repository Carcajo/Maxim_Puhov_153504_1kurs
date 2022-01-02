/*Лабораторная работа №6, задание 9. Выполнил Пухов М.Ю.

В заданной строке, состоящей из букв, цифр и прочих символов, найдите 
сумму всех чисел*/

#include<iostream>
#include<string>

using namespace std;
string input(int minValue, int maxValue) {
	string text;
	while (true)
	{
		getline(cin, text);
		if (text.length() < maxValue && text.length() > minValue)
			return text;
		cin.clear();
		cin.ignore(32000, '\n');
		text = "";
		cout << "Enter correct word" << endl;
	}
}

double numberSum(string line) {

	double sum = 0, tmp;
	double count = 0, fraction, ex;
	bool minus, exMinus;

	while (count < line.length()) {
		minus = false;

		if (isdigit(line[count])) {
			if (count != 0 && line[count - 1] == '-')
			{
				tmp = line[count] - '0';

				minus = true;
			}
			else {
				tmp = line[count] - '0';
			}

			++count;

			while (isdigit(line[count])) {
				tmp = tmp * 10 + (line[count] - '0');

				++count;
			}

			fraction = 1;

			if (line[count] == '.' && isdigit(line[count + 1])) {
				++count;

				while (isdigit(line[count])) {
					fraction *= 10;

					tmp = tmp + (long double)(line[count] - '0') / fraction;

					++count;
				}
			}

			if ((line[count] == 'e' || line[count] == 'E') && (isdigit(line[count + 1]) || (line[count + 1] == '+' && isdigit(line[count + 2])) || (line[count + 1] == '-' && isdigit(line[count + 2])))) {
				exMinus = false;

				++count;

				if (line[count] == '-') {
					exMinus = true;
					++count;
				}
				else if (line[count] == '+') {
					++count;
				}

				ex = line[count] - '0';

				++count;

				while (isdigit(line[count])) {
					ex = ex * 10 + (line[count] - '0');
					++count;
				}

				if (exMinus) {
					ex *= -1;
				}

				tmp *= pow(10, ex);
			}

			if (minus) {
				tmp *= -1;
			}


			sum += tmp;
		}

		++count;
	}

	return sum;
}
int main()
{
	string line = input(0, 101);
	cout << numberSum(line);
	return 0;
}
