#include <iostream>
#include <vector>
#include <string>
#define f(i,a,b) for(int i=a; i<b; i++)
#include <algorithm>
using namespace std;

int		N;

bool	compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first == b.first)
		return (false);
	else
		return (a.first < b.first);
}

int		main(void)
{
	cin >> N;
	vector<pair<int, string> > set;
	pair<int, string> p;

	f(i, 0, N)
	{
		cin >> p.first >> p.second;
		set.push_back(p);
	}
	stable_sort(set.begin(), set.end(), compare);
	f(i, 0, N)
	{
		cout << set[i].first << ' ' << set[i].second << '\n';
	}
	return (0);
}
