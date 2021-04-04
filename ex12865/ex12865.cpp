#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int		N,M;
int		Dp[101][100001];
int		Object[100][2];

void	Input(void)
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> Object[i][0] >> Object[i][1];
	}
}

void	Fill(void)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			int weight = Object[i-1][0];
			int value = Object[i-1][1];
			if (weight <= j)
				Dp[i][j] = max(Dp[i-1][j], Dp[i-1][j-weight] + value);
			else
				Dp[i][j] = Dp[i - 1][j];
		}
}

int		main(void)
{
	Input();
	Fill();
	cout << Dp[N][M] << '\n';
}
