#include <iostream>
#include <vector>
#include <string>
using namespace std;
int		x_move[4] = {1,-1,0,0};
int		y_move[4] = {0,0,1,-1};
int		n,m;
void	change_color(int map[1001][11], int row, int col)
{
	if (map[row][col] == 1)
		map[row][col] = 0;
	else
		map[row][col] = 1;
}

void	click_board(int map[1001][11], int row, int col)
{
	change_color(map, row, col);
	for (int i = 0; i < 4; i++)
	{
		int n_row = row + x_move[i];
		int n_col = col + y_move[i];
		if (n_row < 0 || n_row >= n || n_col < 0 || n_col >= m)
			continue;
		change_color(map, n_row, n_col);
	}
}

int		main(void)
{
	int		MAP[1001][11];
	int		count = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
		}
	}
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (MAP[i - 1][j] == 1)
			{
				click_board(MAP, i, j);
				count++;
			}
		}

	int black = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (MAP[i][j] != 0)
				black++;
		}
	if (black)
		cout << "-1" << endl;
	else
		cout << count << endl;
}

		

