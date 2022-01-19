#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
using namespace std;

int		T;
int		N,M;
deque<pair<int, int> >q;

//queue 사용하고, 일일이 처음부터끝까지 돌아가면서 비교하기 

int		print(void)
{
	int		order = 1;
	pair<int, int> nowDocument;
	bool	flag;
	
	while (!q.empty())
	{
		flag = false;
		nowDocument = q.front();
		for (int k = 1; k < q.size(); k++)
		{
			if (q[k].first > nowDocument.first)
			{
				q.pop_front();
				q.push_back(nowDocument);
				flag = true;
				break ;
			}
		}
		if (!flag)
		{
			q.pop_front();
			if (nowDocument.second == 1)
				return (order);
			order++;
		}
	}
}


int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		q.clear();
		cin >> N >> M; // M 은 찾고싶은 친구가 몇번째로 출력되는지
		for (int j = 0; j < N; j++)
		{
			int		importance;
			int		target;
			if (j == M)
				target = 1;
			else
				target = 0;
			cin >> importance;
			q.push_back(make_pair(importance, target));
		}
		int ret = print();
		cout << ret << endl;
	}
}
