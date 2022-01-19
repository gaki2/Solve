#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#define f(i, a) for (int i = 0; i < a; i++)
using namespace std;

int		N,M;
vector <string> map;
int		g_cnt = 2000000000;
int		visit[1000][1000] = {0,};
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,1,-1};
bool	flag = true;

void	dfs(int	row, int col, int cnt)
{
	int		t_row;
	int		t_col;

	visit[row][col] = 1;
	cnt++;
	if (row == N - 1 && col == M - 1)
	{
		g_cnt = min(g_cnt, cnt);
		return ;
	}
	f(i,4)
	{
		t_row = row + y_move[i];
		t_col = col + x_move[i];
		if (0 <= t_row && t_row <= N - 1 && 0 <= t_col && t_col <= M - 1 && visit[t_row][t_col] == 0 && map[t_row][t_col] == '0')
		{
			dfs(t_row, t_col, cnt);
			visit[t_row][t_col] = 0;
		}
		if (0 <= t_row && t_row <= N - 1 && 0 <= t_col && t_col <= M - 1 && visit[t_row][t_col] == 0 && map[t_row][t_col] == '1' && flag)
		{
			flag = false;
			dfs(t_row, t_col, cnt);
			flag = true;
			visit[t_row][t_col] = 0;
		}
	}
}

int		main(void)
{
	cin >> N >> M;
	f(i, N)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	dfs(0,0,0);
	if (g_cnt == 2000000000)
		printf("-1\n");
	else
		printf("%d\n", g_cnt);
	return (0);
}
