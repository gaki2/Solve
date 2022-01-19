#include <algorithm>
#include <iostream>
#include <vector>
#define f(i, a, b) for(int i=a; i<b; i++)
using namespace std;


int		N;

bool	compare(pair<int, int> a , pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	else
		return (a.first < b.first);
}

int		main(void)
{
	cin >> N;
	pair<int, int> point;
	vector<pair<int, int> > p_set;

	f(i, 0, N)
	{
		cin >> point.first >> point.second;
		p_set.push_back(point);
	}
	sort(p_set.begin(), p_set.end(), compare);
	f(i, 0, N)
	{
		cout << p_set[i].first << ' ' << p_set[i].second << '\n';
	}
	return (0);
}
