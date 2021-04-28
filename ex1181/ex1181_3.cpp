#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string a, string b)
{
	if (a.size() == b.size())
	{
		return (a < b);
	}
	else
		return (a.size() < b.size());
}

int main(void)
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		if (find(v.begin(), v.end(), a) == v.end())
		{
			v.push_back(a);
		}
	}
	sort(v.begin(), v.end(), compare);

	vector<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << '\n';
	}
}
