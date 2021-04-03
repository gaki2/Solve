#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<string> board;
bool check[26] = {false,};
int	g_cnt;
int	x_move[4] = {1,-1,0,0};
int	y_move[4] = {0,0,1,-1};
int	visit[30][30];

bool	is_first(char c)
{
	if (check[c - 'A'])
		return (false);
	else
		return (true);
}

void	rec(int row, int col, int count)
{

	visit[row][col] = 1;
	check[board[row][col] - 'A'] = true;
	for (int i = 0; i < 4; i++)
	{
		int new_row = row + y_move[i];
		int new_col = col + x_move[i];
		if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M) 
			continue;
		if (is_first(board[new_row][new_col]) && !visit[new_row][new_col]) 
		{
			rec(new_row, new_col,count + 1);
		}
	}
	visit[row][col] = 0;
	check[board[row][col] - 'A'] = false;
	g_cnt = max(g_cnt, count);
}

int		main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;	
		board.push_back(temp);
	}
	rec(0,0,1);
	printf("%d\n", g_cnt);
}
