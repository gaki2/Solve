#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int		N;
vector<string> map;
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,-1,1};
int		visit[100][100];
queue<pair<int, int>> q;

void	to_RGsame(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 'R')
				map[i][j] = 'G';
}

void	clear_visit(void)
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			visit[i][j] = 0;
}

void	dfs_cnt(int row, int col, char color)
{
	visit[row][col] = 1;
	for (int i = 0; i < 4; i++)
	{
		int new_row = row + y_move[i];
		int	new_col = col + x_move[i];
		if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= N) continue;
		if (!visit[new_row][new_col] && map[new_row][new_col] == color)
			dfs_cnt(new_row, new_col, color);
		else if(!visit[new_row][new_col] && map[new_row][new_col] != color)
			q.push(make_pair(new_row, new_col));
	}
}
int		g_cnt;
int		g_cnt2;

int		main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	q.push(make_pair(0,0));
	while (!q.empty())
	{
		int	row = q.front().first;
		int	col = q.front().second;
		q.pop();
		if (!visit[row][col])
		{
			dfs_cnt(row, col, map[row][col]);
			g_cnt++;
		}
	}
	to_RGsame();
	clear_visit();

	q.push(make_pair(0,0));
	while (!q.empty())
	{
		int	row = q.front().first;
		int	col = q.front().second;
		q.pop();
		if (!visit[row][col])
		{
			dfs_cnt(row, col, map[row][col]);
			g_cnt2++;
		}
	}
	printf("%d %d\n", g_cnt, g_cnt2);
	return (0);
}


