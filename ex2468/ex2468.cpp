#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N;
int MAP[100][100];
int MAX_HEIGHT = 0;

int VISIT[100][100];
int x_move[4] = {1,-1,0,0};
int y_move[4] = {0,0,-1,1};
stack<pair<int,int>> s;

void init_visit(void)
{
	for (int i = 0; i < 100; i++)
		for (int j =0; j < 100; j++){
			VISIT[i][j] = 0;
		}
}

int search(int rain)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] > rain && !VISIT[i][j]){
				s.push(make_pair(i,j));
				cnt++;
				while (!s.empty())
				{
					int row = s.top().first;
					int col = s.top().second;
					s.pop();
					for (int i = 0; i < 4; i++){
						int d_row = row + y_move[i];
						int d_col = col + x_move[i];
						if (d_row < 0 || d_row >= N || d_col < 0 || d_col >= N)
							continue;
						if (!VISIT[d_row][d_col] && MAP[d_row][d_col] > rain){
							s.push(make_pair(d_row,d_col));
							VISIT[d_row][d_col] = 1;
						}
					}
				}
			}
		}
	return (cnt);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			cin >> MAP[i][j];
			MAX_HEIGHT = max(MAX_HEIGHT, MAP[i][j]);
		}
	int result = 1;
	for (int rain = 1; rain < MAX_HEIGHT; rain++)
	{
		init_visit();
		result = max(search(rain), result);
	}
	cout << result << '\n';
}



			
