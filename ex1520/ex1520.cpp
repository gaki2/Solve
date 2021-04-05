#include <iostream>
#include <memory.h>
using namespace std;

int N, M;
int Map[501][501];
int Dp[501][501];

int	x_move[4] = {1,0,-1,0};
int y_move[4] = {0,1,0,-1};

void Input(void)
{
	ios::sync_with_stdio(0);
	cin >> N >> M;

	for (int i = 1; i <=N; i++)
		for (int j =1; j<=M; j++)
			cin >> Map[i][j];
}

int Dfs(int y, int x)
{
	if (Dp[y][x] != -1) return Dp[y][x];
	if (y <= 0 || y > N || x <= 0 || x > M) return 0;
	if (y == 1 && x == 1) return 1;

	Dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny, nx;
		ny = y + y_move[i];
		nx = x + x_move[i];
		if (Map[ny][nx] > Map[y][x])
			Dp[y][x] += Dfs(ny,nx);
	}
	return Dp[y][x];
}

int main(void)
{
	Input();
	memset(Dp, -1, sizeof(Dp));
	cout << Dfs(N,M) << '\n';
}



