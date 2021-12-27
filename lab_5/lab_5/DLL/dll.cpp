#include "Header.h"
#include <cmath>

extern "C" double __declspec(dllexport) __stdcall fuck(int* a, int q, int t)
{
	if (t == q)
		return 1;
	else
		return (sin(a[q]) - cos(a[q])) * fuck(a, q + 1, t);
}