#include <iostream>
#include <queue>
using namespace std;
int board[300][300];

struct Piece{
	int row;
	int col;
	int cnt;
};

struct Target{
	int row;
	int col;
};

Piece Knight = {0,0,0};
Target target = {0,0};
int N;
int x_move[8] = {2,2,-2,-2,1,-1,1,-1};
int y_move[8] = {1,-1,1,-1,2,2,-2,-2};

void clear_board(void)
{
	for (int i =0 ; i < 300; i++)
		for (int j =0; j < 300; j++)
			board[i][j] = 0;
}

int spread(void)
{
	queue<Piece> q;
	q.push(Knight);
	board[Knight.row][Knight.col] = 1;
	if (Knight.row == target.row && Knight.col == target.col)
		return (0);
	while (!q.empty())
	{
		int now_row = q.front().row;
		int now_col = q.front().col;
		int now_cnt = q.front().cnt;
		//board[now_row][now_col] = 1;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
				int dy = now_row + y_move[i];
				int dx = now_col + x_move[i];
				if (dy == target.row && dx == target.col)
					return (now_cnt + 1);
				else if ((dy >= 0 && dy < N && dx >= 0 && dx < N) && !board[dy][dx])
				{
					q.push({dy,dx,now_cnt+1});
					//board[dy][dx] = 1;
				}
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	int test_num;
	cin >> test_num;
	for (int i = 0; i < test_num; i++)
	{
		clear_board();
		int result = 0;
		cin >> N;
		cin >> Knight.row >> Knight.col >> target.row >> target.col;
		Knight.cnt = 0;
		result = spread();
		cout << result << '\n';
	}
}


		

