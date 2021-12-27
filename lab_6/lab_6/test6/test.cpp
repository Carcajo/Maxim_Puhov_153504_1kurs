#include "pch.h"
#include <cmath>
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int task1(char s1[81], int mas) {
	int i, u, q, g, q1, min, w = 0, o = 1;
	double sum, t;
	char s[81];
	for (int y = 0; y < 81; y++) {
		if (s1[y] == '\0') break;
		s[y] = s1[y];
	}
	//замена "лишнего" на пробел
	for (i = 0; i < 80; i++)
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			s[i] = ' ';
	for (i = 0; i < 80; i++)
		if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] > '9'))
			s[i] = ' ';

	double* r = (double*)malloc(w * sizeof(double));
	for (i = 0; i < 80;) {
		while (s[i] == ' ' && i + 1 < 80) i++;
		if (i + 1 == 80) break;
		u = 1;
		g = i;
		while (s[i + 1] != ' ' && s[i + 1] != '-' && i + 1 < 80) {
			i++;
			u++;
		}
		i = g;
		t = 1;
		sum = 0;
		if (s[i] == '-') {
			i++;
			o = -1;
			u--;
		}
		for (q = u + i - 1; q >= i; q--) {
			sum += (s[q] - '0') * t;
			t *= 10;
		}
		r = (double*)realloc(r, ++w * sizeof(double));
		r[w - 1] = sum * o;
		o = 1;
		i += u + 1;
	}

	//сортировка
	for (i = 0; i < w; i++) {
		min = r[i];
		q1 = i;
		for (q = i; q < w; q++)
			if (min > r[q]) {
				min = r[q];
				q1 = q;
			}
		std::swap(r[i], r[q1]);
	}

	int ret = r[mas];
	free(r);
	return ret;
}

TEST(TestTask1, Test1) {
	EXPECT_EQ(task1("35hg5h4265hg3745hj21 432 534 6234", 2), 35);
	EXPECT_TRUE(true);
}
TEST(TestTask1, Test2) {
	EXPECT_EQ(task1("35hg5h4265hg3745hj21 432 534 6234", 4), 534);
	EXPECT_TRUE(true);
}
TEST(TestTask1, Test3) {
	EXPECT_EQ(task1("54325hkhk6456f-64564fre", 0), -64564);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

int task2(char s1[81]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int w = 1, gl_ = 0, sog = 0, gh = 0;
	char gl[21] = "аиеЄоуыэю€ј»≈®ќ”џЁёя";

	char* s = (char*)malloc(w * sizeof(char));
	while (s[gh - 1] != '\0') {
		s[gh++] = s1[gh];
		s = (char*)realloc(s, ++w * sizeof(char));
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < 21; j++)
			if (gl[j] == s[i] && s[i] != '\0') {
				gl_++;
				break;
			}
		if (s[i] >= 'а' && s[i] <= '€' || s[i] >= 'ј' && s[i] <= 'я') sog++;
	}
	sog -= gl_;
	int ret;
	if (gl_ > sog) ret = 1;
	if (gl_ < sog) ret = 0;
	free(s);
	return ret;
}

TEST(TestTask2, Test1) {
	EXPECT_EQ(task2("цуцуцуц"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask2, Test2) {
	EXPECT_EQ(task2("цуцуууууцц"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask2, Test3) {
	EXPECT_EQ(task2("цуцу534534цц"), 0);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

int task3(char s1[81]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int w = 1, w1 = 1, p = 0, st_ = 1, b = 0, gh = 0;


	char* s = (char*)malloc(w * sizeof(char));
	while (s[gh - 1] != '\0') {
		s[gh++] = s1[gh];
		s = (char*)realloc(s, ++w * sizeof(char));
	}

	char* buf = new char[gh];

	for (int j = 0, j1 = gh - 1; j < gh - 1; j++, j1--)
		buf[j1] = s[j];

	for (int j = 0, j1 = 1; j < gh - 1; j++, j1++) {
		if (buf[j1] == s[j]) continue;
		else b++;
	}
	int ret;
	if (b) {
		b = 0;
		ret = 0;
	}
	else  ret = 1;

	delete[] buf;

	free(s);

	return ret;
}

TEST(TestTask3, Test1) {
	EXPECT_EQ(task3("ывы"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask3, Test2) {
	EXPECT_EQ(task3("вап4пав"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask3, Test3) {
	EXPECT_EQ(task3("ывкы"), 0);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

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

string task4(string rt) {
	string st, buf;
	st = rt;
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
		}
	return st;
}

TEST(TestTask4, Test1) {
	EXPECT_EQ(task4("Too swift for Theex, too quick for Gallow"), "Tu svift for Ziks, tu kvik for Galov");
	EXPECT_TRUE(true);
}

TEST(TestTask4, Test2) {
	EXPECT_EQ(task4("Too strong for young Prince Joseph to follow"), "Tu strong for ung Prinse Josef to folov");
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

int task5(double L, int m, string s, string s2) {
	int p;
	if (s2.length() == L || s.length() == L)return 0;
	p = L - s2.length() - s.length();
	if (p < 0) return 1;
	return fmod(pow(26, p) * 2, m);
}

TEST(TestTask5, Test1) {
	EXPECT_EQ(task5(14, 1000, "asa", "asasas"), 752);
	EXPECT_TRUE(true);
}
TEST(TestTask5, Test2) {
	EXPECT_EQ(task5(7, 123, "russian", "codecup"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask5, Test3) {
	EXPECT_EQ(task5(7, 15, "codec", "decup"), 1);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////


int rec(string& st, int d, int& i) {
	if (st[i] != st[i + 1]) return 1;
	int b = 0;
	if (st[i] == st[i + 1]) b++;
	i++;
	return b + rec(st, d, i);
}

double fact(int a) {
	if (a == 1) return 1;
	return a * fact(a - 1);
}

int task6(string st) {
	int d, q1;
	double an;
	char min;

	d = st.length();
	//сортировка
	for (int i = 0; i < d; i++) {
		min = st[i];
		q1 = i;
		for (int q = i; q < d; q++)
			if (min > st[q]) {
				min = st[q];
				q1 = q;
			}
		swap(st[i], st[q1]);
	}

	an = fact(d);
	for (int i = 0; i < d; i++)
		an /= fact(rec(st, d, i));

	return an;
}

TEST(TestTask6, Test1) {
	EXPECT_EQ(task6("SOLO"), 12);
	EXPECT_TRUE(true);
}

TEST(TestTask6, Test2) {
	EXPECT_EQ(task6("asdf"), 24);
	EXPECT_TRUE(true);
}

TEST(TestTask6, Test3) {
	EXPECT_EQ(task6("reghfsdh"), 20160);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

int  task7(string st) {
	string buf, buf2, buf3;
	bool t = 0;
	int d, q, q1, r = 0, w = 0;

	while (st.find(' ') != -1) st.erase(st.find(' '), 1);

	buf3 = st;
	buf2 = st;
	d = st.length();
	for (q1 = 1; q1 < d; q1++) {
		for (q = 1; q < st.length(); q++) {
			buf = st;
			buf.erase(q + 1, st.length());
			w = 0;

			for (r = 1; r < buf.length(); r++)
				if (buf[r] == buf[buf.length() - 1 - r]) w++;

			if (w == buf.length() - 1) {
				st.erase(0, w / 2 + w % 2 - 1);
				buf2[w / 2 + w % 2 + q1 - 1] = ' ';
				break;
			}
		}
		st.erase(0, 1);
	}

	for (int f = 0; f < buf2.length(); f++)
		if (buf2[f] == buf2[f + 1]) {
			buf2.erase(f, 1);
			f = -1;
		}

	buf2 += ' ';
	if (buf2.length() == 3) {
		r = -1;
	}
	else
		for (;;) {
			d = buf2.find(' ');
			if (d == -1) break;
			if (d + 1 > r) r = d + 1;
			buf2.erase(0, d + 1);
		}
	if (r > buf3.length()) r = buf3.length();
	return r;
}

TEST(TestTask7, Test1) {
	EXPECT_EQ(task7("asa"), 2);
	EXPECT_TRUE(true);
}

TEST(TestTask7, Test2) {
	EXPECT_EQ(task7("asdfds"), 4);
	EXPECT_TRUE(true);
}

TEST(TestTask7, Test3) {
	EXPECT_EQ(task7("asdfghjkl"), 9);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

void search_r(string s, string t, int q, int r, int& y, int i) {
	if (q + 1 < s.length() && q >= 0 && !i && s[q + 1] == t[r]) {
		q++;
		r++;
		y++;
		return search_r(s, t, q, r, y, i);
	}
	else {
		if (q < s.length() && q - 1 >= 0 && s[q - 1] == t[r]) {
			q--;
			r++;
			y++;
			i++;
			return search_r(s, t, q, r, y, i);
		}
		else return;
	}
}
void search_l(string s, string t, int q, int r, int& y, int i) {
	if (q < s.length() && q - 1 >= 0 && s[q - 1] == t[r] && !i) {
		q--;
		r++;
		y++;
		return search_l(s, t, q, r, y, i);
	}
	else {
		if (q + 1 < s.length() && q >= 0 && s[q + 1] == t[r]) {
			q++;
			r++;
			y++;
			i++;
			return search_l(s, t, q, r, y, i);
		}
		else return;
	}
}

int task8(string s, string t) {
	int q, r = 0, y = 0, y1;

	y1 = 0;
	for (q = 0; q < s.length(); q++) {
		if (s[q] == t[r]) {
			r++;
			y = 1;
			search_r(s, t, q, r, y, 0);
			if (y > y1) y1 = y;
			r = 1;
			y = 1;
			search_r(s, t, q, r, y, 0);
			if (y > y1) y1 = y;
			r = 0;
		}
	}

	int ret;
	if (y1 == t.length())ret = 1;
	else ret = 0;
	return ret;
}

TEST(TestTask8, Test1) {
	EXPECT_EQ(task8("abcdef", "cdedcb"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test2) {
	EXPECT_EQ(task8("aaa", "aaaaa"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test3) {
	EXPECT_EQ(task8("aab", "baaa"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test4) {
	EXPECT_EQ(task8("ba", "baa"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test5) {
	EXPECT_EQ(task8("ab", "b"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test6) {
	EXPECT_EQ(task8("abcdef", "abcdef"), 1);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////////////////////////////////////////////////////

int task9(string s) {
	int i, u, q, g, o = 1;
	double sum, t, sum1 = 0;

	//замена "лишнего" на пробел
	for (i = 0; i < s.length(); i++)
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			s[i] = ' ';
	s += ' ';
	for (i = 0; i < s.length(); i++)
		if (s[i] == '-' && s[i + 1] == ' ')
			s[i] = ' ';
	for (i = 0; i < s.length(); i++)
		if (s[i] == '-' && s[i - 1] != ' ' && s[i + 1] != ' ')
			s.insert(i, " ");

	for (i = 0; i < s.length();) {
		while (s[i] == ' ' && i + 1 < s.length()) i++;
		if (i + 1 == s.length()) break;
		u = 1;
		g = i;
		while (s[i + 1] != ' ' && s[i + 1] != '-' && i + 1 < s.length()) {
			i++;
			u++;
		}
		i = g;
		t = 1;
		sum = 0;
		if (s[i] == '-') {
			i++;
			o = -1;
			u--;
		}
		for (q = u + i - 1; q >= i; q--) {
			sum += (s[q] - '0') * t;
			t *= 10;
			if (u > 250) {
				sum = 0;
				break;
			}
		}
		sum1 += sum * o;
		o = 1;
		i += u + 1;
	}
	return sum1;
}

TEST(TestTask9, Test1) {
	EXPECT_EQ(task9("6h54jg63hj6f63f3k6hj"), 202);
	EXPECT_TRUE(true);
}

TEST(TestTask9, Test2) {
	EXPECT_EQ(task9("1324-1234klgf4"), 94);
	EXPECT_TRUE(true);
}

TEST(TestTask9, Test3) {
	EXPECT_EQ(task9("ijhi435uh-234234dfd9732"), -224067);
	EXPECT_TRUE(true);
}
