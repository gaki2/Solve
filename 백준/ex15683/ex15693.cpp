#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int	N,M;
int	map[8][8];
int	temp[8][8];
int cctv_dir[8];
int	g_cnt = 65;
vector<pair<int, int>> cctv;

int		map_check(void)
{
	int		cnt = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (temp[i][j] == 0)
				cnt++;
	return (cnt);
}

void	map_copy(void)
{
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			temp[i][j] = map[i][j];
}

int		x[5] = {0,-1,0,0,1};
int		y[5] = {0,0,-1,1,0};

void	detect(int row, int col, int di)
{
	int ny = row;
	int	nx = col;

	while (1)
	{
		ny += y[di];
		nx += x[di];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			return ;
		if (temp[ny][nx] == 6)
			return ;
		temp[ny][nx] = 7;
	}
}

void	search(void)
{
	for (int i =0; i < cctv.size(); i++)
	{
		int row = cctv[i].first;
		int col = cctv[i].second;

		int	type = map[row][col];
		int	di = cctv_dir[i];
		if (type == 1)
		{
			detect(row, col, di);
		}
		else if (type == 2)
		{
			if (di == 1 || di == 4)
			{
				detect(row, col, 1);
				detect(row, col, 4);
			}
			else if (di == 2 || di == 3)
			{
				detect(row, col, 2);
				detect(row, col, 3);
			}
		}
		else if (type == 3)
		{
			if (di == 1)
			{
				detect(row, col, 2);
				detect(row, col, 4);
			}
			else if (di == 2)
			{
				detect(row, col, 3);
				detect(row, col, 4);
			}
			else if (di == 3)
			{
				detect(row, col, 3);
				detect(row, col, 1);
			}
			else if (di == 4)
			{
				detect(row, col, 1);
				detect(row, col, 2);
			}
		}
		else if (type == 4)
		{
			if (di == 1)
			{
				detect(row, col, 2);
				detect(row, col, 3);
				detect(row, col, 4);
			}
			else if (di == 2)
			{
				detect(row, col, 1);
				detect(row, col, 3);
				detect(row, col, 4);
			}
			else if (di == 3)
			{
				detect(row, col, 1);
				detect(row, col, 2);
				detect(row, col, 4);
			}
			else if (di == 4)
			{
				detect(row, col, 1);
				detect(row, col, 2);
				detect(row, col, 3);
			}
		}
		else if (type == 5)
		{
			detect(row, col, 1);
			detect(row, col, 2);
			detect(row, col, 3);
			detect(row, col, 4);
		}
	}
}

void	dfs(int order)
{
	if (order == cctv.size())
	{
		map_copy();
		search();
		g_cnt = min(g_cnt, map_check());
		return ;
	}

	for (int i = 1; i < 5; i++)
	{
		cctv_dir[order] = i;
		dfs(order + 1);
		cctv_dir[order] = 0;
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{	
				cctv.push_back(make_pair(i,j));
			}
		}
	dfs(0);
	cout << g_cnt << '\n';
}



		

