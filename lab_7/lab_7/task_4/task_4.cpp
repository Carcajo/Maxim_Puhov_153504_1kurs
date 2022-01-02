/*Лабораторная работа №7, задание 4, вариант 5. Выполнил Пухов М.Ю.

 Осуществить сложение и вычитание чисел в  в девятнадцатеричной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.*/
#include<iostream>
#include<string>

using namespace std;

int inputInt() {

	double x;
	while (true)
	{
		cin >> x;
		if (!std::cin.fail())
			return (int)x;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter corect value" << endl;
	}
}
int inputInt(int minValue, int maxValue) {

	double x;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail() && x <maxValue && x > minValue)
			return (int)x;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter corect value" << endl;
	}
}

std::string enterNumber(std::string& numberInOtherSystem, int valueOfOtherSystem) {

	while (true)
	{
		std::cin >> numberInOtherSystem;
		if (checkNumber(numberInOtherSystem, valueOfOtherSystem))
			return numberInOtherSystem;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter corect value" << std::endl;
	}
}

bool checkNumber(std::string str, int valueOfOtherSystem) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!(findValue((char)tolower(str[i]), valueOfOtherSystem) + 1))
			return false;
	}
	return true;
}

char findValue(int digit, int maxKey) {
	int key[18]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	char value[18]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h' };
	for (int i = 0; i < maxKey; i++)
	{
		if (key[i] == digit)
			return value[i];
	}
	return 0;
}


int findValue(char digit, int maxKey) {
	char key[18]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h' };
	int value[18]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	for (int i = 0; i < maxKey; i++)
	{
		if (key[i] == digit)
			return i;
	}
	return -1;
}



int convertToDecimal(std::string str, int valueOfOtherSystem) {
	int number = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		number += (findValue((char)(tolower(str[i])), valueOfOtherSystem)) * pow(valueOfOtherSystem, str.length() - 1 - i);
	}
	return number;
}

void convertFromDecimal(int number, int valueOfOtherSystem, std::string& numberInAnotherSystem) {
	while (number != 0)
	{
		numberInAnotherSystem.push_back(findValue(number % valueOfOtherSystem, valueOfOtherSystem));
		number /= valueOfOtherSystem;
	}
	reverseStr(numberInAnotherSystem);
}


int convertToDecimalFromReverse(std::string str, int valueOfOtherSystem) {
	int number = 1;

	convertBinariesInReverseCode(str);
	if (str[0] == '1')
	{
		str.erase(0, 1);
		number *= -1;
	}
	number *= convertToDecimal(str, 2);

	return number;
}

std::string transformNumber(std::string str) {
	std::string newStr;
	addZeroes(str, newStr);
	for (int i = 0; i < str.length(); i++)
	{
		newStr.push_back(str[i]);
	}
	return newStr;
}

void addZeroes(std::string& str, std::string& newStr) {
	if ((int)log2(str.length()) != log2(str.length()))
	{
		for (int i = 0; i < pow(2, (int)log2(str.length()) + 1) - str.length(); i++)
		{
			newStr.push_back('0');
		}
	}
}

std::string convertInReverseCode(int num) {
	std::string number;
	convertFromDecimal(num, 2, number);
	convertBinariesInReverseCode(number);
	return number;
}

void convertBinariesInReverseCode(std::string& str) {
	str = transformNumber(str);
	if (str[0] == '1') {

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
				str[i] = '0';
			else
				str[i] = '1';
		}

	}
}



std::string binarySum(std::string& firstNumber, std::string& secondNumber, int valueOfSystem)
{
	reverseStr(firstNumber);
	reverseStr(secondNumber);
	if (firstNumber.length() > secondNumber.length())
		for (int i = secondNumber.length(); i < firstNumber.length(); i++)
		{
			secondNumber.push_back('0');
		}
	else if (firstNumber.length() < secondNumber.length())
		for (int i = firstNumber.length(); i < secondNumber.length(); i++)
		{
			firstNumber.push_back('0');
		}

	std::string sumNumber;
	int length = firstNumber.length(), tmp = 0;

	for (int i = 0;i < length; i++)
	{
		std::cout << (findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp) << std::endl;
		if (findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp < valueOfSystem)
		{
			sumNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp), valueOfSystem));
			tmp = 0;
		}
		else
		{
			sumNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp - valueOfSystem, valueOfSystem));
			tmp = 1;
		}
	}

	if (tmp != 0)
		sumNumber.push_back(findValue(tmp, valueOfSystem));

	reverseStr(sumNumber);

	return sumNumber;
}


std::string binaryDif(std::string& firstNumber, std::string& secondNumber, int valueOfSystem) {
	if (firstNumber.length() > secondNumber.length())
		for (int i = secondNumber.length(); i < firstNumber.length(); i++)
		{
			secondNumber.push_back('0');
		}
	else if (firstNumber.length() < secondNumber.length())
		for (int i = firstNumber.length(); i < secondNumber.length(); i++)
		{
			firstNumber.push_back('0');
		}

	std::string difNumber;
	int length = firstNumber.length(), tmp = 0;

	for (int i = 0; i < length; i++)
	{
		if (findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) > 0)
		{
			difNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem)), valueOfSystem));
		}
		else
		{
			difNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) + valueOfSystem, valueOfSystem));
			firstNumber[i + 1] = findValue(findValue(firstNumber[i + 1], valueOfSystem) - 1, valueOfSystem);
		}
	}

	reverseStr(difNumber);

	return difNumber;
}
void reverseStr(std::string& str) {
	for (int i = 0; i < str.length() / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = tmp;
	}
}

int main() {
	char signOfFirstNumber, signOfSecondNumber;
	string firstNumber, secondNumber;

	cout << "Enter sign of first number" << endl;
	cin >> signOfFirstNumber;
	cout << "Enter first numbers in 13-al system" << endl;
	enterNumber(firstNumber, 16);
	cout << "Enter sign of second number" << endl;
	cin >> signOfSecondNumber;
	cout << "Enter second numbers in 13-al system" << endl;
	enterNumber(secondNumber, 16);

	if (convertToDecimal(firstNumber, 16) > convertToDecimal(secondNumber, 16))
	{
		if (signOfFirstNumber == '-' && signOfSecondNumber == '+')
		{
			cout << "-" << binaryDif(secondNumber, firstNumber, 16) << endl;
			cout << "-" << binarySum(firstNumber, secondNumber, 16) << endl;
		}
		if (signOfFirstNumber == '+' && signOfSecondNumber == '-')
		{
			cout << binaryDif(firstNumber, secondNumber, 16) << endl;
			cout << binarySum(firstNumber, secondNumber, 16) << endl;
		}
		if (signOfFirstNumber == '+' && signOfSecondNumber == '+')
		{
			cout << binarySum(firstNumber, secondNumber, 16) << endl;
			cout << binaryDif(firstNumber, secondNumber, 16) << endl;
		}
		if (signOfFirstNumber == '-' && signOfSecondNumber == '-') {
			cout << "-" << binarySum(firstNumber, secondNumber, 16) << endl;
			cout << "-" << binaryDif(firstNumber, secondNumber, 16) << endl;
		}

	}
	else {
		if (signOfFirstNumber == '-' && signOfSecondNumber == '+')
		{
			cout << binaryDif(secondNumber, firstNumber, 16) << endl;
			cout << "-" << binarySum(firstNumber, secondNumber, 16) << endl;
		}
		if (signOfFirstNumber == '+' && signOfSecondNumber == '-')
		{
			cout << "-" << binaryDif(secondNumber, firstNumber, 16) << endl;
			cout << binarySum(firstNumber, secondNumber, 16) << endl;
		}
		if (signOfFirstNumber == '+' && signOfSecondNumber == '+')
		{
			cout << binarySum(firstNumber, secondNumber, 16) << endl;
			cout << "-" << binaryDif(secondNumber, firstNumber, 16) << endl;
		}
		if (signOfFirstNumber == '-' && signOfSecondNumber == '-') {
			cout << "-" << binarySum(firstNumber, secondNumber, 16) << endl;
			cout << binaryDif(secondNumber, firstNumber, 16) << endl;
		}
	}
}
