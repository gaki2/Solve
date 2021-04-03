#include <iostream>
#include <algorithm>
#include <queue>
#define Max 300000
using namespace std;

int		N,K;
pair<int, int> info[Max];
int		bag[Max];
priority_queue<int> que;
long long	cnt;

int		main(void)
{
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	int		index = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> info[i].first >> info[i].second;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}
	sort(bag, bag + K);
	sort(info, info + N);

	for (int i = 0; i < K; i++)
	{
		while (index < N && info[index].first <= bag[i])
		{
			que.push(info[index].second);
			index++;
		}
		if (!que.empty())
		{
			cnt += que.top();
			que.pop();
		}
	}
	cout << cnt << '\n';
	return (0);
}


