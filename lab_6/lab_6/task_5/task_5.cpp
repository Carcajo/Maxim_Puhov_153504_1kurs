/*Лабораторная работа №6, задание 5. Выполнил Пухов М.Ю.

Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m */

#include <iostream>
#include<string>

using namespace std;
int inputInt(int min, int max)
{
	int a;
	while (true)
	{
		cin >> a;
		if (a< max && a > min)
			return a;
		cin.clear();
		cin.ignore(32000, '\n');
		cout << "Enter correct word" << endl;
	}
}
int WordFound(const int& L, const int& m, const string s1, const string s2)
{
	int ans = 1;
	int size1 = s1.length();
	int size2 = s2.length();
	if (L > size1 + size2)
	{
		for (int i = 0; i < L - size1 - size2; i++)
			ans = (ans * 26) % m;
		ans = (ans * 2) % m;
		return ans;
	}
	else
	if (L == size1 + size2)
		return 2;
	else
	{
		ans = 2;					
		int j = 0;												//индекс общих символов для суффикс
		for (int i = L - size2; i < size1; i++, j++)			//s1 - префикс s2 - суффикс, i - индекс общих символов для префикса 
			if (s1[i] != s2[j])									
			{
				ans--;
				break;
			}
		j = 0;
		for (int i = L - size1; i < size2; i++, j++)			//s1 - суффикс s2 - префикс
			if (s2[i] != s1[j])
			{
				ans--;
				break;
			}
		return ans;
	}
}

int main()
{
	int counter = inputInt(0, 101);
	while (counter > 0)
	{
		int L = inputInt(0, 10e9 + 1), m = inputInt(0, 10e4 + 1);
		string s1, s2;
		cin.ignore(32767, '\n');
		getline(cin, s1);
		getline(cin, s2);
		cout << WordFound(L, m, s1, s2) << endl;
		--counter;
	}
}
