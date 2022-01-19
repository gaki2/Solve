#include <iostream>
#include <algorithm>

using namespace std;
int		map[50][50];
int		visit[50][50];
int		x_move[4] = {-1,0,1,0};
int		y_move[4] = {0,-1,0,1};
pair<pair<int, int>,int> robot;
int		g_cnt = 1;
int		N,M;

void	move(void)
{
	int		new_row;
	int		new_col;
	int		rotation_cnt = 0;

	while (1)
	{
		int direction = robot.second;
		int	row = robot.first.first;
		int	col = robot.first.second;

		visit[row][col] = 1;
		if (rotation_cnt == 4)
		{
			new_row = row + y_move[(direction + 2) % 4];
			new_col = col + x_move[(direction + 2) % 4];
			if (map[new_row][new_col] == 1)
				break ;
			else
			{
				robot.first.first = new_row;
				robot.first.second = new_col;
				rotation_cnt = 0;
				continue ;
			}
		}

		if (direction == 1)
		{
			new_col = col + x_move[0];
			if (map[row][new_col] == 0 && !visit[row][new_col])
			{
				robot.first.second  = new_col;
				robot.second = 4;
				rotation_cnt = 0;
				g_cnt++;
			}
			else
			{
				robot.second = 4;
				rotation_cnt++;
			}
		}	
		else if (direction == 2)
		{
			new_row = row + y_move[1];
			if (map[new_row][col] == 0 && !visit[new_row][col])
			{
				robot.first.first  = new_row;
				robot.second = 1;
				rotation_cnt = 0;
				g_cnt++;
			}
			else
			{
				robot.second = 1;
				rotation_cnt++;
			}
		}
		else if (direction == 3)
		{
			new_col = col + x_move[2];
			if (map[row][new_col] == 0 && !visit[row][new_col])
			{
				robot.first.second  = new_col;
				robot.second = 2;
				rotation_cnt = 0;
				g_cnt++;
			}
			else
			{
				robot.second = 2;
				rotation_cnt++;
			}
		}
	
		else if (direction == 4)
		{
			new_row = row + y_move[3];
			if (map[new_row][col] == 0 && !visit[new_row][col])
			{
				robot.first.first  = new_row;
				robot.second = 3;
				rotation_cnt = 0;
				g_cnt++;
			}
			else
			{
				robot.second = 3;
				rotation_cnt++;
			}
		}
	}
}
	

int		main(void)
{
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	cin >> robot.first.first >> robot.first.second >> robot.second;
	robot.second = robot.second + 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	move();
	cout << g_cnt << '\n';
}
	

