#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int		N;

bool	compare(string a, string b)
{
	if (a.size() == b.size())
		return (a < b);
	else
		return (a.size() < b.size());
}

int		main(void)
{
	scanf("%d", &N);
	vector <string> set;
	string word;

	for (int i = 0; i < N; i++)
	{
		cin >> word;
		if (find(set.begin(), set.end(), word) == set.end())
			set.push_back(word);
	}
	sort(set.begin(), set.end(), compare);
	for (auto i : set)
		cout << i << '\n';
	return (0);
}
