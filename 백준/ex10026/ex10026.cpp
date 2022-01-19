#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int		N;
vector<string> map;
queue<pair<int, int>> q;
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,1,-1};
int		visit[100][100] = {0,};

void	dfs(int	row, int col, char now_color)
{
	visit[row][col] = 1;
	for (int i = 0; i < 4; i++)
	{
		int	new_row = row + y_move[i];
		int	new_col = col + x_move[i];
		if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= N) continue;
		if (!visit[new_row][new_col] && now_color == map[new_row][new_col])
			dfs(new_row, new_col, now_color);
		else if (!visit[new_row][new_col])
			q.push(make_pair(new_row, new_col));
	}
}

void	init_visit(void)
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			visit[i][j] = 0;
}

int		g_cnt;
int		g_cnt2;

int		main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	q.push(make_pair(0,0));
	while (!q.empty())
	{
		int	row,col;
		row = q.front().first;
		col = q.front().second;
		q.pop();
		if (!visit[row][col])
		{
			g_cnt++;
			dfs(row, col, map[row][col]);
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 'R')
				map[i][j] = 'G';
	init_visit();
	q.push(make_pair(0,0));
	while (!q.empty())
	{
		int	row,col;
		row = q.front().first;
		col = q.front().second;
		q.pop();
		if (!visit[row][col])
		{
			g_cnt2++;
			dfs(row, col, map[row][col]);
		}
	}
	printf("%d %d\n", g_cnt, g_cnt2);
	return (0);
}
