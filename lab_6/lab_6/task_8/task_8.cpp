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