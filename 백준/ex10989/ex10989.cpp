#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		N;
vector<int> set(10001, 0);

int		main(void)
{
	scanf("%d",&N);
	int		num;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		set[num]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		while (set[i] != 0)
		{
			printf("%d\n", i);
			set[i]--;
		}
	}
	return (0);
}
