#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> map;
int		N, M;
int		x_move[4] = {1, -1, 0, 0};
int		y_move[4] = {0, 0, 1, -1};
int		visit[1000][1000][2] = {0,};

/*
struct	edge
{
	int		x;
	int		y;
	int		cost;
	bool	wall;

	edge(int _x, int _y, int _cost, int _wall)
	{
		x = _x;
		y = _y;
		cost = _cost;
		wall = _wall;
	}
};*/

int		go_map(int row, int col)
{
	queue<pair<pair<int, int>, int>> q;
	queue<int> w;

	q.push(make_pair(make_pair(row, col), 1));
	w.push(1);
	visit[row][col][1] = 1;
	while (!q.empty())
	{
		pair<int, int>	point = q.front().first;
		int		cnt = q.front().second;
		int		wall = w.front();
		q.pop();
		w.pop();
		if (point.first == N - 1 && point.second == M - 1)
			return (cnt);
		for (int i = 0; i < 4; i++)
		{
			int		new_row = point.first + y_move[i];
			int		new_col = point.second + x_move[i];
			if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M)
				continue;
			if (visit[new_row][new_col][wall] == 0 && map[new_row][new_col] == '0')
			{
				visit[new_row][new_col][wall] = 1;
				q.push(make_pair(make_pair(new_row, new_col), cnt + 1));
				w.push(wall);
			}
			else if (visit[new_row][new_col][wall] == 0 && map[new_row][new_col] == '1' && wall)
			{
				wall = 0;
				visit[new_row][new_col][wall] = 1;
				q.push(make_pair(make_pair(new_row, new_col), cnt + 1));
				w.push(wall);
			}
		}
	}
	return (-1);
}

int		main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	printf("%d", go_map(0,0));
	return (0);
}
