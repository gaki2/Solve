#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result = 2100000000;


int two_Check(int i, int j, vector<string> board)
{
	int cnt = 0;
	for (int ii = i; ii < i + 8; ii++)
		for (int jj = j; jj < j + 8; jj++)
		{
			if ((ii + jj) % 2 == 0)
			{
				char even_char = 'W';
				if (even_char != board[ii][jj])
					cnt++;
			}
			else if ((ii + jj) % 2 == 1)
			{
				char odd_char = 'B';
				if (odd_char != board[ii][jj])
					cnt++;
			}
		}
	return (cnt);
}


int one_Check(int i, int j, vector<string> board)
{
	int cnt = 0;
	for (int ii = i; ii < i + 8; ii++)
		for (int jj = j; jj < j + 8; jj++)
		{
			if ((ii + jj) % 2 == 0)
			{
				char even_char = 'B';
				if (even_char != board[ii][jj])
					cnt++;
			}
			else if ((ii + jj) % 2 == 1)
			{
				char odd_char = 'W';
				if (odd_char != board[ii][jj])
					cnt++;
			}
		}
	return (cnt);
}

int main(void)
{
	ios::sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	vector<string> board;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		board.push_back(a);
	}

	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
		{
			result = min(result, one_Check(i, j, board));
			result = min(result, two_Check(i, j, board));
		}
	cout << result ;
}
			




