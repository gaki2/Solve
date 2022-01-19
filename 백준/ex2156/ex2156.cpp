#include <iostream>
#include <algorithm>
using namespace std;

int		N;
int		grape[10001];
int		dp[10001];
int		g_max;
int		main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &grape[i]);
	}
	dp[0] = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + grape[i], max(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 1]));
	}
	for (int i = 1; i <= N; i++)
	{
		if (g_max < dp[i])
			g_max = dp[i];
	}
	printf("%d\n", g_max);
}




