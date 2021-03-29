#include <iostream>
#include <algorithm>
using namespace std;
int		N;
int		map[502][502];
int		dp[502][502];
int		g_max;

int		main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
		{
			cin >> map[i][j];
		}
	dp[1][1] = map[1][1];
	for (int i = 2; i <= N; i++)
		for (int j = 1; j<= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + map[i][j];
		}
	for (int i = 1; i <= N; i++)
	{
		if (dp[N][i] > g_max)
			g_max = dp[N][i];
	}
	printf("%d", g_max);
}
