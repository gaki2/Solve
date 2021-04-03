#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> zero_place;
int		board[9][9];
int		value[9] = {1,2,3,4,5,6,7,8,9};
bool	flag = false;

bool	valid_row(int row, int col)
{
	int	test = board[row][col];

	for (int i = 0; i < 9; i++)
	{
		if (test == board[row][i] && i != col)
			return (false);
	}
	return (true);
}

bool	valid_col(int row, int col)
{
	int	test = board[row][col];

	for (int j = 0; j < 9; j++)
	{
		if (test == board[j][col] && j != row)
			return (false);
	}
	return (true);
}

bool	valid_square(int row, int col)
{
	int	test = board[row][col];
	int	row_range = (row / 3) * 3;
	int	col_range = (col / 3) * 3;
	for (int i = row_range; i < row_range + 3; i++)
		for (int j = col_range; j < col_range + 3; j++)
		{
			if ( test == board[i][j] && i != row && i != col)
				return (false);
		}
	return (true);
}

void	rec(int pair_index)
{
	int	row = zero_place[pair_index].first;
	int	col = zero_place[pair_index].second;
	
	if (row == - 1)
	{
		flag = true;
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
			{
				printf("%d", board[j][k]);
				if (k == 8)
					printf("\n");
				else
					printf(" ");
			}
		return ;
	}
	
	for (int i = 0; i < 9; i++)
	{
		board[row][col] = value[i];
		if (valid_row(row, col) && valid_col(row, col) && valid_square(row, col) && !flag)
		{
			rec(pair_index + 1);
		}
		board[row][col] = 0;

	}
}

int		main(void)
{
	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				zero_place.push_back(make_pair(i,j));
			}
		}
	zero_place.push_back(make_pair(-1,-1));
	rec(0);
}



