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
bool Pol(const string& word)
{
	for (int i = 0; i < word.length() / 2; i++)
	{
		if (word[i] != word[word.length() - i - 1])
			return false;
	}
	return true;
}
int PolLine(const string& word) {
	int PolLine = 0;
	string nonePolindromLine;
	for (int i = 0; i < word.length(); i++)
	{
		nonePolindromLine += word[i];
		if (!Pol(nonePolindromLine) || i == 0)
			PolLine++;
		else
			break;
	}
	if (PolLine == 1)
		return -1;
	else
		return PolLine;
}
void main()
{
	cout << PolLine(input(0, 106));

}