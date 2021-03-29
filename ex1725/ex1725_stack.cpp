#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int		N;

int		main(void)
{
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		long long ans = 0;
		long long set[100002] = {0,};
		for (int i = 1; i <= N; i++)
		{		
			scanf("%lld", &set[i]);
		}
		stack<long long> s;
		s.push(0);
		for (long long i = 1; i <= N + 1; i++)
		{
			while (set[s.top()] > set[i])
			{
				long long height = s.top();
				s.pop();
				ans = max(ans, set[height] * (i - s.top() - 1));
			}
			s.push(i);
		}
		printf("%lld\n", ans);
	}
	return (0);
}
