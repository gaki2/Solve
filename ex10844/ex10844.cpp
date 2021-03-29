#include <iostream>
#include <algorithm>
using namespace std;

int			N;
long long	dp[100][10] = {{0,1,1,1,1,1,1,1,1,1}};
int		main(void)
{
	cin >> N;
	for (int i = 1; i < 100; i++)
	{
		dp[i][0] = dp[i - 1][1] ;
		dp[i][9] = dp[i - 1][8] ;
		for (int j = 1; j < 9; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	long long	sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum += dp[N - 1][i];
		sum %= 1000000000;
	}
	printf("%lld\n", sum);
}


