#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int		main(void)
{
	int		a;
	int		b;

	a = ceil(log2(8));
	printf("a:%d\n", a);
	b = (1 << (a + 1));
	printf("b:%d\n", b);
	return (0);
}

