#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int		N, M;
vector<string> copy_map;
vector<string> map;
int		visit[8][8];
string line;
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,1,-1};
queue<pair<int, int>> virus;
int		g_cnt = 0;

void	bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visit[row][col] = 1;
	while (!q.empty())
	{
		int r = q.front().first;
		int	c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	new_row = r + y_move[i];
			int	new_col = c + x_move[i];
			if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) continue;
			if (copy_map[new_row][new_col] == '0' && visit[new_row][new_col] == 0)
			{
				copy_map[new_row][new_col] = '2';
				visit[new_row][new_col] = 1;
				q.push(make_pair(new_row, new_col));
			}
		}
	}
}

void	init_visit(void)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			visit[i][j] = 0;
}

void	find_virus(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == '2')
			{
				virus.push(make_pair(i,j));
			}
}

void	check_num(void)
{
	int		cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (copy_map[i][j] == '0')
				cnt++;
		}
	g_cnt = max(g_cnt, cnt);
}

void	make_wall_play(void)
{
	for (int i = 0; i < N*M; i++)
	{
		for (int j = i + 1; j < M*N; j++)
		{
			for (int k = j + 1; k < M*N; k++)
			{
				if (map[i/M][i%M] == '0' && map[j/M][j%M] == '0' && map[k/M][k%M] == '0')
				{
					copy_map = map;
					init_visit();
					copy_map[i/M][i%M] = '1';
					copy_map[j/M][j%M] = '1';
					copy_map[k/M][k%M] = '1';
					find_virus();
					while (!virus.empty())
					{
						int		row;
						int		col;
						row = virus.front().first;
						col = virus.front().second;
						virus.pop();
						bfs(row, col);
					}
					check_num();
				}
			}
		}
	}
}

int		main(void)
{
	cin >> N >> M;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, line);
		for (int j = 0; j < line.size(); j++)
			if (line[j] == ' ') line.erase(j, 1);
		map.push_back(line);
	}
	make_wall_play();
	printf("%d\n", g_cnt);
	return (0);
}




