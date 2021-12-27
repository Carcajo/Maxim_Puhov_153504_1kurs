#include "pch.h"
#include <string>
using namespace std;
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
TEST(TestCaseName1, TestName1) {
	EXPECT_EQ(752, WordFound(14 1000, const(cup,russia)));
	EXPECT_TRUE(true);
}
