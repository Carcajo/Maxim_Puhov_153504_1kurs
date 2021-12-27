#include<iostream>
using namespace std;
int input() {
	int x;
	while (true)
	{
		cin >> x;
		if (!cin.fail())
			return x;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter correct value!";
	}
}

char inputStr() {
	char letter;
	while (true)
	{
		cin >> letter;
		if ((letter > 64 && letter < 81) || (letter > 96 && letter < 123))
			return letter;
		letter = '\0';
		cout << "Enter correct value! " << endl;
	}
}
void translateToDigits(char* line, int size) {

	for (int i = 0; i < size; i++)
	{
		cout << tolower((int)*line++) - 96;
	}

}

int main() {
	cout << "Enter size of your line" << endl;

	int size = input();
	char* str = new char[size];
	char* line = str;

	cout << "Enter letter in your line" << endl;
	for (int i = 0; i < size; i++)
	{
		*line++ = inputStr();
	}

	translateToDigits(str, size);
	return 0;
}