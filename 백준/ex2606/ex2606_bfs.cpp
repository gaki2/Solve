#include <iostream>
#include <queue>
using namespace std;
int INFO[101][101];
int N, M;
int COMPUTER[101];
int answer;
queue<int> q;

void spread(void)
{
	for (int i = 2; i <= N; i++)
	{
		if (INFO[1][i])
		{
			q.push(i);
			COMPUTER[i] = 1;
			answer++;
		}
	}
	while (!q.empty())
	{
		int com = q.front();
		q.pop();
		for (int i = 2; i <= N; i++)
		{
			if (INFO[com][i] && !COMPUTER[i])
			{
				q.push(i);
				COMPUTER[i] = 1;
				answer++;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		INFO[a][b] = 1;
		INFO[b][a] = 1;
	}
	spread();
	cout << answer << '\n';
}




