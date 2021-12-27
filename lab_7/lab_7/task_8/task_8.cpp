#include <iostream>
#include <string>
using namespace std;

void to_binary(int a, string& s) {
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

int main() {

	short ourDigit = 0, n; cin >> n;

	string a = "10", b = "8", c = "1", d = "100", e = "1000";

	for (short i = 1; i <= 10000; ++i) {

		string digit = to_string(i);

		bool same = 0;

		string binary; to_binary(i, binary);

		for (short j = 0; binary != digit; ++j) {
			if (binary.length() == 0) break;
			binary.erase(0, 1);
		}

		if (binary.length()) same = 1;
		if (same) ++ourDigit; if (ourDigit == n) { cout << i; break; }

		short A = atoi(a.c_str());
		short B = atoi(b.c_str());
		short C = atoi(c.c_str());
		short D = atoi(d.c_str());
		short E = atoi(e.c_str());
		if (i % A == C) {
			i += B;
			a.push_back('0');
			b.push_back('8');
			c.push_back('1');
		}
		else if (i % E == 11) {
			i += 88;
			e.push_back('0');
		}
		else if ((i % D) % 10 == 1 && i != 1) {
			i += 8;
			d.push_back('0');
			continue;
		}
	}
	return (0);
}