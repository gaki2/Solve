#include <iostream>
#include <vector>

using namespace std;

int		N,M;
vector<int> v;
int		Longest;
int		ret;

void	binary(int start, int end)
{
	long long	ans = 0;
	if (start > end)
		return ;
	int mid = (start + end) / 2;

	for (auto i : v)
	{
		if (i - mid > 0)
			ans += (i - mid);
	}
	if (ans > M)
	{
		ret = mid;
		binary(mid + 1, end);
	}
	else if (ans < M)
	{
		binary(start, mid - 1);
	}
	else
	{
		ret = mid;
		return ;
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int		h;
		cin >> h;
		if (h > Longest)
			Longest = h;
		v.push_back(h);
	}
	binary(0,Longest);
	cout << ret << endl;
}





