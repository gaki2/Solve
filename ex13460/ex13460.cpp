#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int		N,M;
int		r_cnt;
int		b_cnt;
int		r_visit[10][10];
vector<string> map;
queue<pair<pair<int, int>, pair<int,int>>> r;
queue<pair<pair<int, int>, int>> b;
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,1,-1};

int		search(void)
{
	while (!r.empty())
	{
		int	r_row = r.front().first.first;
		int	r_col = r.front().first.second;
		int	b_row = b.front().first.first;
		int	b_col = b.front().first.second;
		r_cnt = r.front().second.first;
		b_cnt = b.front().second;
		bool flag = r.front().second.second;
		r.pop();
		b.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr_row = r_row + y_move[i];
			int nb_row = b_row + y_move[i];
			int nr_col = r_col + x_move[i];
			int nb_col = b_col + x_move[i];
			if (!r_visit[nr_row][nr_col])
			{
				while (map[nr_row][nr_col] == ' ' || map[nr_row][nr_col] == 'B')
				{
					if (map[nr_row][nr_co] == 'O' return (r_cnt);
					nr_row = nr_row + y_move[i];
					nr_col = nr_col + x_move[i];
				}
				while (map[nb_row][nb_col] == ' ' || map[nb_row][nb_col] == 'R')
				{
					nb_row = nb_row + y_move[i];
					nb_col = nb_col + x_move[i];
				}
				if (nr_row == nb_row && nr_col == nb_col)
				{
					flag = true;
					if (i == 0)
					{
						int move = r_col > b_col ? 0 : 1;
						nr_col = nr_col - move;
						nb_col = nb_col + (move - 1);
					}
					else if (i == 1)
					{
						int move = r_col > b_col ? 0 : 1;
						nr_col = nr_col + (move - 1);
						nb_col = nb_col - move;
					}
					else if (i == 2)
					{
						int move = r_row > b_row ? 0 : 1;
						nr_row = nr_row + (move - 1);
						nb_row = nb_row - move;
					}
					else if (i == 3)
					{
						int move = r_row > b_row ? 0 : 1;
						nr_row = nr_row - move;
						nb_row = nb_row + (move - 1);
					}
				}
				else
					flag = false;
				r.push(make_pair(make_pair(nr_row - y_move[i], nr_col - x_move[i]), make_pair(r_cnt + 1, flag)));
				b.push(make_pair(make_pair(nb_row - y_move[i], nb_col - x_move[i]), b_cnt + 1));
			}
		}
	}
}


int		main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '#')
			{
				r_visit[i][j] = 1;
			}
			if (map[i][j] == 'R')
				r.push(make_pair(make_pair(i, j), make_pair(0, false)));
			if (map[i][j] == 'B')
				b.push(make_pair(make_pair(i,j), 0));
		}
	printf("%d",search());
	return (0);
}
