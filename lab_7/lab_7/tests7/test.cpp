Тесты. Выполнил Пухов М.Ю.
#include "gtest/gtest.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long double t1chek_nine(long double buf, long double a) {
	if (buf < 1) return 0;
	buf = trunc(buf / 10) * 10;
	if (a - buf == 9) return -1;
	a = trunc(a / 10);
	buf /= 10;
	return t1chek_nine(buf, a);
}

long double t1to_ten(long double buf, long double a, long double b, int t) {
	if (buf < 1) return 0;
	buf = trunc(buf / 10) * 10;
	b = (a - buf) * pow(9, t++);
	a = trunc(a / 10);
	buf /= 10;
	return b + t1to_ten(buf, a, b, t);
}

string task1(double a)
{
	long double b, ten = 1, ele = 0, s, o;
	int t = 0, minus = 1;
	string l;
	if (a < 0) {
		minus = -1;
		a *= -1;
	}
	b = t1to_ten(a, a, 0, 0);
	s = b;
	while (s >= 1) {
		o = fmod(s, 11);
		if (o == 10) l += 'A';
		else l += o + '0';
		s = trunc(s / 11);
	}

	for (int j = 0, j1 = l.length() - 1; j < l.length() / 2; j++, j1--)
		swap(l[j], l[j1]);
	if (minus == -1) l.insert(0, "-");
	return l;
}

TEST(task_1, test1) {
  EXPECT_EQ(task1(1234), "769");
  EXPECT_TRUE(true);
}
TEST(task_1, test2) {
	EXPECT_EQ(task1(6432), "3608");
	EXPECT_TRUE(true);
}
TEST(task_1, test3) {
	EXPECT_EQ(task1(3125), "17A3");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

string t2to_dva(string s, string dva, int t, int k, int c) {
	for (;;) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			dva += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			dva += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) dva += '1';
				else  dva += '0';
				t = 0;
			}
		}
	}

	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);

	return dva;
}

string t2after_dot(string s, string s2, string dva) {
	s2.erase(0, s2.find('.') + 1);
	if (s2.length() > 10) s2.erase(8, s2.length() - 1);
	s.erase(s.find('.'), s.length());
	dva = t2to_dva(s, dva, 0, 0, 0);
	dva += '.';
	int size = s2.length() - 1;
	double dota = 0;
	for (int d = 0; d < s2.length(); d++) dota += pow(10, size--) * (s2[d] - '0');
	size = s2.length();
	for (int d = 0; d < 10; d++) {
		dota *= 2;
		if (dota - pow(10, size) > 0) {
			dva += '1';
			dota -= pow(10, size);
		}
		else dva += '0';
	}
	return dva;
}

string task2(string s) {
	string dva, s2;
	int p = 0;
	bool dot = 0;
	char minus[] = "0";

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}

	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
			dot++;
		}
		while (p > 1) {
			cout << "Incorrect value\n";
			return 0;
		}
	}

	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.') {
			cout << "Incorrect value\n";
			return 0;
		}
	}

	if (!dot) dva = t2to_dva(s, dva, 0, 0, 0);
	else dva = t2after_dot(s, s, dva);

	dva.insert(0, minus);
	dva.insert(1, ",");

	return dva;
}

TEST(task_2, test1) {
	EXPECT_EQ(task2("431613"), "0,1101001010111111101");
	EXPECT_TRUE(true);
}
TEST(task_2, test2) {
	EXPECT_EQ(task2("16321"), "0,11111111000001");
	EXPECT_TRUE(true);
}
TEST(task_2, test3) {
	EXPECT_EQ(task2("231621"), "0,111000100011000101");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t3swap_cod(string& dva) {
	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);
}

string t3to_dva(string s, string dva, int t, int k, int c) {
	for (;;) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			dva += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			dva += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) dva += '1';
				else  dva += '0';
				t = 0;
			}
		}
	}

	t3swap_cod(dva);

	return dva;
}

string t3after_dot(string s, string s2, string dva) {
	s2.erase(0, s2.find('.') + 1);
	if (s2.length() > 10) s2.erase(8, s2.length() - 1);
	s.erase(s.find('.'), s.length());
	dva = t3to_dva(s, dva, 0, 0, 0);
	dva += '.';
	int size = s2.length() - 1;
	double dota = 0;
	for (int d = 0; d < s2.length(); d++) dota += pow(10, size--) * (s2[d] - '0');
	size = s2.length();
	for (int d = 0; d < 10; d++) {
		dota *= 2;
		if (dota - pow(10, size) > 0) {
			dva += '1';
			dota -= pow(10, size);
		}
		else dva += '0';
	}
	return dva;
}

bool t3cin_string(string& s, char* minus, int p, bool& dot) {
	//getline(cin, s);

	if (s.find('.') == -1) {
		s.insert(s.length(), ".");
		s.insert(s.length(), "0000000000");
	}

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}
	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
			dot++;
		}
		while (p > 1) {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.') {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	return 1;
}

string t3dop_code(string dva, char* minus) {
	if (minus[0] == '0') return dva;
	string s, s2;
	int tt = 0, z;
	if (dva[1] == ',') {
		tt = 1;
		if (dva[0]) z = 1;
		else z = 0;
		dva.erase(0, 2);
	}
	t3swap_cod(dva);
	dva.erase(10, 1);
	s += '1';

	int dot = 10;
	if (dva.find('1') > 9)dva.erase(0, 10);
	else {
		dot = dva.find('1');
		dva.erase(0, dot);
	}

	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == '0') dva[y] = '1';
		else dva[y] = '0';
	}

	for (int y = 0, n = 0; y < dva.length(); y++) {
		s += '0';
		n = 1;
	}

	int c;
	bool t = 0;
	for (int y = 0; y < dva.length(); y++) {
		c = dva[y] + s[y] - 2 * '0' + t;
		if (c < 2) {
			s2 += c + '0';
			t = 0;
		}
		else {
			s2 += '0';
			t = 1;
		}
	}
	s = "";
	for (int y = 0; y < dot; y++) s += '0';
	s2 = s + s2;
	s2.insert(10, ".");
	t3swap_cod(s2);
	if (tt) {
		if (z) s2.insert(0, "1");
		else s2.insert(0, "0");
		s2.insert(1, ",");
	}
	return s2;
}

bool t3cin_to_dop(string& s, string& dva) {
	bool dot = 0;
	char minus[] = "0";

	if (!t3cin_string(s, minus, 0, dot)) return 0;
	dva = t3after_dot(s, s, dva);
	dva = t3dop_code(dva, minus);
	dva.insert(0, minus);
	dva.insert(1, ",");
	return 1;
}

string t3summa(string dva, string dva2) {
	string s;
	dva.erase(1, 1);
	dva2.erase(1, 1);

	t3swap_cod(dva);
	t3swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);

	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	bool t = 0;
	int c;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		c = dva[y] + dva2[y] - 2 * '0' + t;
		switch (c) {
		case 2:
			s += '0';
			t = 1; break;
		case 3:
			s += '1';
			t = 1; break;
		default:
			s += c + '0';
			t = 0; break;
		}
	}
	s.insert(10, ".");
	t3swap_cod(s);
	s.insert(1, ",");
	return s;
}

string task3(string s, string s2) {
	string dva, dva2;

	if (!t3cin_to_dop(s, dva)) return 0;
	if (!t3cin_to_dop(s2, dva2)) return 0;
	s = t3summa(dva, dva2);
	char minus[2];
	minus[0] = s[0];
	s = t3dop_code(s, minus);
	return s;
}

TEST(task_3, test1) {
	EXPECT_EQ(task3("1253", "6431"), "0,1111000000100.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_3, test2) {
	EXPECT_EQ(task3("312857", "132875632187"), "0,1111011110000000001100000010001010100.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_3, test3) {
	EXPECT_EQ(task3("83", "1"), "0,1010100.0000000000");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t4swap_cod(string& dva) {
	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);
}

bool t4cin_string(string& s, char* minus) {
	//getline(cin, s);
	int p = 0;

	if (s.find('.') == -1) {
		s.insert(s.length(), ".");
		s.insert(s.length(), "0000000000");
	}

	if (s[0] == '-') {
		minus[0] = '1';
		s.erase(0, 1);
	}
	for (int e = 0; e < s.length(); e++) {
		if (s[e] == '.' || s[0] == '.' || s[s.length() - 1] == '.') {
			p++;
		}
		while (p > 1) {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	for (int e = 0; e < s.length(); e++) {
		while ((s[e] < '0' || s[e]>'9') && s[e] != '.' && s[e] != 'A') {
			cout << "Incorrect value\n";
			return 0;
		}
	}
	return 1;
}

bool t4cin_to_dop(string& s) {
	char minus[] = "0";

	if (!t4cin_string(s, minus)) return 0;
	if (minus[0] == '1') s = '-' + s;
	return 1;
}

string t4summa(string dva, string dva2) {
	string s;

	t4swap_cod(dva);
	t4swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);
	dva += '0';
	dva2 += '0';
	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == 'A') dv = 10;
		else dv = dva[y] - '0';
		if (dva2[y] == 'A') dv2 = 10;
		else dv2 = dva2[y] - '0';
		c = dv + dv2 + t;
		if (c < 10) {
			s += c + '0';
			t = 0;
			continue;
		}
		if (c == 10) {
			s += 'A';
			t = 0;
			continue;
		}
		c--;
		if (c > 10) {
			s += c + '0' - 10;
			t = 1;
			continue;
		}
		if (c == 10) {
			s += '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	t4swap_cod(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

string t4subtraction(string dva, string dva2) {
	string s;

	t4swap_cod(dva);
	t4swap_cod(dva2);

	dva.erase(10, 1);
	dva2.erase(10, 1);
	dva += '0';
	dva2 += '0';
	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	int c, t = 0, dv, dv2;
	s = "";
	for (int y = 0; y < dva.length(); y++) {
		if (dva[y] == 'A') dv = 10;
		else dv = dva[y] - '0';
		if (dva2[y] == 'A') dv2 = 10;
		else dv2 = dva2[y] - '0';
		c = dv - dv2 - t;
		if (c >= 0) {
			s += c + '0';
			t = 0;
			continue;
		}
		else c = 11 + c;
		if (c == 10) {
			s += 'A';
			t = 1;
			continue;
		}
		if (c >= 0) {
			s += c + '0';
			t = 1;
			continue;
		}
	}
	s.insert(10, ".");
	t4swap_cod(s);
	while (s[0] == '0') s.erase(0, 1);
	if (s[0] == '.') s.insert(0, "0");
	return s;
}

string task4(string s, string s2, bool g) {
	string  s3;

	if (!t4cin_to_dop(s)) return 0;
	if (!t4cin_to_dop(s2)) return 0;

	s3 = t4summa(s, s2);
	if (g) return s3;
	if (s.length() > s2.length()) s3 = t4subtraction(s, s2);
	else {
		s3 = t4subtraction(s2, s);
		s3.insert(0, "-");
	}
	if (!g) return s3;
}
TEST(task_4, test1) {
	EXPECT_EQ(task4("1324", "6132",1), "7456.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_4, test2) {
	EXPECT_EQ(task4("3126", "741141347",1), "741144472.0000000000");
	EXPECT_TRUE(true);
}
TEST(task_4, test3) {
	EXPECT_EQ(task4("3126", "741141347",0), "-741139221.0000000000");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t5swap_cod(string& dva) {
	for (int j = 0, j1 = dva.length() - 1; j < dva.length() / 2; j++, j1--)
		swap(dva[j], dva[j1]);
}

void t5subtraction(string& dva, string dva2, string& s2, char f) {
	string s;
	t5swap_cod(dva);
	t5swap_cod(dva2);

	//cout << "\n\n" << dva;

	if (dva.length() > dva2.length())
		for (int y = 0, y1 = dva.length() - dva2.length(); y < y1; y++)
			dva2 += '0';
	if (dva.length() < dva2.length())
		for (int y = 0, y1 = dva2.length() - dva.length(); y < y1; y++)
			dva += '0';

	int c, t = 0, dv, dv2;
	for (int y = 0; y < dva.length(); y++) {
		dv = dva[y] - '0';
		dv2 = dva2[y] - '0';
		c = dv - dv2 - t;
		if (c >= 0) {
			s += c + '0';
			t = 0;
			continue;
		}
		else c = 10 + c;
		if (c >= 0) {
			s += c + '0';
			t = 1;
			continue;
		}
	}
	s2 += f;
	t5swap_cod(s);
	while (s[0] == '0') s.erase(0, 1);
	dva = s;
}

void t5change(string& s2) {
	t5swap_cod(s2);
	string buf = s2 + '0', buf2;
	int c = 1;
	for (int a = 0; a < buf.length(); a++) {
		if (buf[a] == buf[a + 1]) {
			c++;
			continue;
		}
		else {
			if (c == 4) {
				buf2 += buf[a] - '0' + 1 + '0';
				buf2 += buf[a];
				buf.erase(0, c);
				a = -1;
				c = 1;
				continue;
			}
			if (c == 6) {
				buf2 += buf[a];
				buf2 += buf[a] - '0' + 1 + '0';
				buf.erase(0, c);
				a = -1;
				c = 1;
				continue;
			}
			if (c == 7) {
				for (int l = 0; l < 2; l++) buf2 += buf[a];
				buf2 += buf[a] - '0' + 1 + '0';
				buf.erase(0, c);
				a = -1;
				c = 1;
				continue;
			}
			if (c == 8) {
				for (int l = 0; l < 3; l++) buf2 += buf[a];
				buf2 += buf[a] - '0' + 1 + '0';
				buf.erase(0, c);
				a = -1;
				c = 1;
				continue;
			}
			if (c == 9) {
				buf2 += buf[a] - '0' + 1 + '0';
				buf2 += buf[a];
				buf.erase(0, c);
				a = -1;
				c = 1;
				continue;
			}
			for (int y = 0; y < c; y++) buf2 += buf[y];
			buf.erase(0, c);
			a = -1;
			c = 1;
		}
	}
	s2 = buf2;
	t5swap_cod(s2);
}

void t5change2(string& s2) {
	string buf;
	for (int a = 0; a < s2.length(); a++) {
		switch (s2[a] - '0') {
		case 1: buf += 'I'; break;
		case 2: buf += 'V'; break;
		case 3: buf += 'X'; break;
		case 4: buf += 'L'; break;
		case 5: buf += 'C'; break;
		case 6: buf += 'D'; break;
		case 7: buf += 'M'; break;
		}
	}
	s2 = buf;
}

string task5(string s) {
	string s2;

	for (int e = 0; e < s.length(); e++)
		while (s[e] < '0' || s[e]>'9') {
			cout << "Incorrect value\n";
			return 0;
		}

	while (s.length() > 3) t5subtraction(s, "1000", s2, '7');
	while (s.length() == 3 && (s[0] - '0') % 5 == 0) t5subtraction(s, "500", s2, '6');
	while (s.length() == 3) t5subtraction(s, "100", s2, '5');
	while (s.length() == 2 && (s[0] - '0') % 5 == 0) t5subtraction(s, "50", s2, '4');
	while (s.length() == 2) t5subtraction(s, "10", s2, '3');
	while ((s[0] - '0') % 5 == 0) t5subtraction(s, "5", s2, '2');
	while (s.length()) t5subtraction(s, "1", s2, '1');
	t5change(s2);
	t5change2(s2);
	return s2;
}

TEST(task_5, test1) {
	EXPECT_EQ(task5("3461"), "MMMCDLXI");
	EXPECT_TRUE(true);
}
TEST(task_5, test2) {
	EXPECT_EQ(task5("1326"), "MCCCXXVI");
	EXPECT_TRUE(true);
}
TEST(task_5, test3) {
	EXPECT_EQ(task5("123"), "CXXIII");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t6sum(double& n) {
	double buf = n, buf1 = 0;
	while (n >= 1) {
		buf = trunc(buf / 10) * 10;
		buf1 += n - buf;
		buf /= 10;
		n = trunc(n / 10);
	}
	n = buf1;
}

double task6(double n)
{
	double n1, n2, tt;
	tt = 0;
	for (double b = 1; b <= n; b++) {
		//cout << b << '\n';
		n1 = b + 1;
		n2 = b;
		t6sum(n1);
		t6sum(n2);
		if (n1 < n2) tt++;
	}
	return tt;
}

TEST(task_6, test1) {
	EXPECT_EQ(task6(633), 63);
	EXPECT_TRUE(true);
}
TEST(task_6, test2) {
	EXPECT_EQ(task6(342724), 34272);
	EXPECT_TRUE(true);
}
TEST(task_6, test3) {
	EXPECT_EQ(task6(3246), 324);
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

bool t7check(double t, char g) {
	double buf = 0;
	while (buf <= t) {
		buf += g;
		if (buf == t) return 1;
	}
	return 0;
}

bool task7(double t, int d)
{
	if (d == 1) {
		if (t7check(t, 7)) return 1;
		else return 0;
	}
	if (d == 2) {
		if (t7check(t, 73)) return 1;
		else return 0;
	}
	if (d == 3) {
		if (t7check(t, 109)) return 1;
		else return 0;
	}
}
TEST(task_7, test1) {
	EXPECT_EQ(task7(8723,1), 0);
	EXPECT_TRUE(true);
}
TEST(task_7, test2) {
	EXPECT_EQ(task7(8723,2), 0);
	EXPECT_TRUE(true);
}
TEST(task_7, test3) {
	EXPECT_EQ(task7(8723,3), 0);
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

void t8bin(int a, string& s) {
	int mx = 0;
	while ((a >> mx++) > 1);
	int num = a, bin;
	while (mx > 0) {
		bin = pow(2, --mx);
		if (num < bin) s += '0';
		else {
			s += '1';
			num -= bin;
		}
	}
}

int task8(int n) {
	int our = 0;

	for (int i = 1; i <= 10000; ++i) {
		bool sa = 0;
		string bina, dig = to_string(i);
		t8bin(i, bina);

		for (int j = 0; bina != dig; ++j) {
			if (bina.length() == 0) break;
			bina.erase(0, 1);
		}

		if (bina.length()) sa = 1;
		if (sa) ++our;
		if (our == n) return i;
	}
}
TEST(task_8, test1) {
	EXPECT_EQ(task8(1), 1);
	EXPECT_TRUE(true);
}
TEST(task_8, test2) {
	EXPECT_EQ(task8(2), 10);
	EXPECT_TRUE(true);
}
TEST(task_8, test3) {
	EXPECT_EQ(task8(10), 1100);
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

string task9(int n) {
	string s;
	while (n) {
		s += n % 3 + '0';
		n /= 3;
	}
	for (int j = 0, j1 = s.length() - 1; j < s.length() / 2; j++, j1--)
		swap(s[j], s[j1]);
	return s;
}

TEST(task_9, test1) {
	EXPECT_EQ(task9(7), "21");
	EXPECT_TRUE(true);
}
TEST(task_9, test2) {
	EXPECT_EQ(task9(22), "211");
	EXPECT_TRUE(true);
}
//////////////////////////////////////////////////////////////////////////////////////////

int task10(int b, bool y) {
	int r;
	double t;
	if (b > 0 && b < 49) r = 1;
	if (b > 48 && b < 97) r = 2;
	if (b > 96 && b < 145) r = 3;
	if (b > 144 && b < 193) r = 4;
	if (b > 192 && b < 241) r = 5;
	t = (b - (r - 1) * 48) / 2.0 + 24;
	if (y) return r;
	else return t;
}
TEST(task_10, test1) {
	EXPECT_EQ(task10(48,1), 1);
	EXPECT_TRUE(true);
}
TEST(task_10, test2) {
	EXPECT_EQ(task10(90, 1), 2);
	EXPECT_TRUE(true);
}
TEST(task_10, test3) {
	EXPECT_EQ(task10(90, 0), 45);
	EXPECT_TRUE(true);
}
