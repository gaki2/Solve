#include <iostream>
#include <algorithm>
#include <vector>
// 수 묶기

using namespace std;

int		N;
int		cnt;

void	right(vector<int> set, int last_idx)
{
	while (last_idx >= 1 && set[last_idx] > 1 && set[last_idx - 1] > 1)
	{
		cnt += set[last_idx] * set[last_idx - 1];
		last_idx = last_idx - 2;
	}
	while (last_idx >= 0 && set[last_idx] > 0)
	{
		cnt += set[last_idx];
		last_idx--;
	}
}

void	left(vector<int> set, int begin_idx)
{
	while (begin_idx < N - 1 && set[begin_idx] <= 0 && set[begin_idx + 1] <= 0)
	{
		cnt += set[begin_idx] * set[begin_idx + 1];
		begin_idx = begin_idx + 2;
	}
	if (set[begin_idx] < 0)
		cnt += set[begin_idx];
	if (begin_idx + 1 < N && set[begin_idx + 1] == 0)
		cnt -= set[begin_idx];
}

int		main(void)
{
	vector<int> set;
	scanf("%d", &N);
	int		temp;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		set.push_back(temp);
	}
	sort(set.begin(), set.end());
	right(set, N - 1);
	left(set, 0);
	printf("%d\n", cnt);
	return (0);
}
