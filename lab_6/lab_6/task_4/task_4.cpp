#include <iostream>
#include <string>
using namespace std;

void change(string& st, int s, char a, char b) {
	if (st[s] == a) st[s] = b;
	else st[s] = b - 32;
}
void two_two(string& st, int& s, char a, char a2, char b, char b2) {
	if ((st[s] == a || st[s] == a - 32) && st[s + 1] == a2) {
		st[s + 1] = b2;
		change(st, s, a, b);
		s++;
	}
}
void two_one(string& st, int s, int& l, char a, char a2, char b) {
	if ((st[s] == a || st[s] == a - 32) && st[s + 1] == a2) {
		st.erase(s + 1, 1);
		change(st, s, a, b);
		l--;
	}
}
void one(string& st, int s, char a, char b) {
	if (st[s] == a || st[s] == a - 32) change(st, s, a, b);
}

int main()
{
	string st, buf;
	for (;;) {
		getline(cin, buf);
		if (buf.length() == 0) break;
		if (buf.length() > 100) {
			cout << "\nString > 100 words, try again\n";
			continue;
		}
		st += buf + '\n';
	}
	int bu, l = st.length();
	for (int s = 0; s < l; s++) {
		if (st[s] == 'x' || st[s] == 'X') {
			st.insert(s + 1, "s");
			change(st, s, 'x', 'k');
			l++;
			s++;
			continue;
		}

		if ((st[s] == 'Y' || st[s] == 'y') && st[s + 1] == 'o' && st[s + 2] == 'u') {
			st.erase(s + 1, 2);
			change(st, s, 'y', 'u');
			l -= 2;
			continue;
		}

		if (st[s] == 'C' || st[s] == 'c') {
			if (st[s + 1] == 'e' || st[s + 1] == 'i' || st[s + 1] == 'y') change(st, s, 'c', 's');
			else change(st, s, 'c', 'k');
			continue;
		}

		two_two(st, s, 'q', 'u', 'k', 'v');
		two_one(st, s, l, 'p', 'h', 'f');
		two_one(st, s, l, 'o', 'o', 'u');
		two_one(st, s, l, 'e', 'e', 'i');
		two_one(st, s, l, 't', 'h', 'z');
		one(st, s, 'w', 'v');
		one(st, s, 'q', 'k');
	}
	for (int s = 0; s < l; s++)
		if ((st[s] >= 'a' && st[s] <= 'z' || st[s] >= 'A' && st[s] <= 'Z') && st[s + 1] == st[s]) {
			l--;
			st.erase(s + 1, 1);
			s--;
		}
	cout << st;
}