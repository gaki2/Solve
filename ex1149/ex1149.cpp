#include <iostream>
#include <algorithm>
int		N;
int		cost[1001][3];
int		dp[1001][3];
using namespace std;
int		main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
	}
	printf("%d\n", min(dp[N][0], min(dp[N][1], dp[N][2])));
}


