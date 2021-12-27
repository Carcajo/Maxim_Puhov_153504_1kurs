#include "pch.h"
using namespace std;
// task_dop_1                 ##########################
int fun(int n)
{
	if (n % 10 > 0)
		return n % 10;
	else if (n == 0)
		return 0;
	else
		return fun(n / 10);

}

int s(int p, int q)
{
	int sum = 0;
	for (int i = p; i <= q; i++)
	{
		sum += fun(i);
	}
	return sum;
}
TEST(TestCaseName1, TestName1) {
	EXPECT_EQ(46, s(1, 10));
	EXPECT_TRUE(true);
}

TEST(TestCaseName1, TestName2) {
	EXPECT_EQ(48, s(10, 20));
	EXPECT_TRUE(true);
}

TEST(TestCaseName1, TestName3) {
	EXPECT_EQ(52, s(30, 40));
	EXPECT_TRUE(true);
}

//task_dop_2                       ####################################  ???????????????


// task_dop_3
int  del_m(int n)
{
	if (n % 2 == 0)
	{
		n = del_m(n / 2);
	}
	return n;
}

int sum_m(int n)
{
	if (n == 0) return 0;
	int del = del_m(n);
	n--;
	del += sum_m(n);
	return del;
}

TEST(TestCaseName2, TestName1) {
	EXPECT_EQ(21, sum_m(7));
	EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName2) {
	EXPECT_EQ(1, sum_m(1));
	EXPECT_TRUE(true);
}
TEST(TestCaseName2, TestName3) {
	EXPECT_EQ(201537, sum_m(777));
	EXPECT_TRUE(true);
}


