#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int		set[100002];
int		N;
int		ans;

int		main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &set[i]);
	}

	stack<int> s;
	s.push(0);
	for (int i = 1; i <= N + 1; i++)
	{
		while (set[s.top()] > set[i])
		{
			int		height = s.top();
			ans = max(ans, set[height] * (i - s.top()));
			s.pop();
		}
		s.push(i);
	}
	printf("%d\n", ans);
	return (0);
}
