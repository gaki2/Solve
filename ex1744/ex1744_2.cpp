#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int		N;
int		cnt = 0;

void	right(vector<int> set, int index)
{
	while (index >= 1 && set[index] > 1 && set[index - 1] > 1)
	{
		cnt += set[index] * set[index - 1];
		index = index - 2;
	}
	while (index >= 0 && set[index] > 0)
		cnt += set[index--];
}

void	left(vector<int> set, int index)
{
	while (index < N - 1 && set[index] <= 0 && set[index + 1] <= 0)
	{
		cnt += set[index] * set[index + 1];
		index = index + 2;
	}
	if (index < N && set[index] < 0)
		cnt += set[index];
}

int		main(void)
{
	scanf("%d", &N);
	int		temp;
	vector<int> set;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		set.push_back(temp);
	}
	sort(set.begin(), set.end());
	right(set, N - 1);
	left(set, 0);
	printf("%d", cnt);
	return (0);
}
