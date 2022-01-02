/*Лабораторная работа №6, задание 8. Выполнил Пухов М.Ю.

	У вас есть строка s и фишка, которую вы можете поставить на любой символ 
этой строки.
После того, как вы поставите фишку, вы можете подвинуть ее вправо 
несколько (возможно, ноль) раз, то есть сделать следующее действие 
несколько раз: если текущая позиция фишки обозначена как i, фишка 
перемещается в позицию i+1. Конечно же, это действие невозможно, если 
фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее 
влево несколько (возможно, ноль) раз, то есть сделать следующее действие 
несколько раз: если текущая позиция фишки обозначена как i, фишка 
перемещается в позицию i−1. Конечно же, это действие невозможно, если 
фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на 
котором оказалась фишка. Например, если строка s — abcdef, вы ставите 
фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3 
раза, вы выпишете строку cdedcb.
Вам даны две строки s и t. Ваше задание — определить, можно ли так 
выполнить описанные операции со строкой s, что в результате вы выпишете 
строку t.
*/
#include<iostream>
#include<string>

using namespace std;
string input(int min, int max) {
	string text;
	while (true)
	{
		cin >> text;
		if (text.length() < max && text.length() > min)
			return text;
		cin.clear();
		cin.ignore(32000, '\n');
		text = "";
		cout << "Enter correct word" << endl;
	}
}
int inputInt(int min, int max) {
	int x;
	while (true)
	{
		cin >> x;
		if (x < max && x > min)
			return x;
		cin.clear();
		cin.ignore(32000, '\n');
		cout << "Enter correct word" << std::endl;
	}
}
bool Word(const string& Word1, const string& Word2, int index) {

	int ind = 0;                //переходящий индекс

	for (index; index < Word1.length(); index++)
	{
		if (Word1[index] != Word2[ind])
			break;
		++ind;
	}
	index -= 2;
	while (ind != Word2.length())
	{
		if (index == -1 || Word1[index] != Word2[ind])
			return false;
		--index;
		++ind;
	}

	return true;

}

string MakeWord(const string& Word1, const string& Word2) {
	for (int i = 0; i < Word1.length(); i++)
	{
		if (Word1[i] == Word2[0])
		{
			if (Word(Word1,Word2, i))
				return "YES";
		}
	}
	return "NO";
}
int main()
{
	int count = inputInt(0, 501);

	while (count > 0)
	{
		string Word1 = input(0, 501), Word2 = input(0, 2 * Word1.length());
		cout << MakeWord(Word1, Word2) << endl;
		--count;
	}
	return 0;

}
