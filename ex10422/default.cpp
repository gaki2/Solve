#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
int		T;
vector<int> v;
ll	DP[5001];

void	rec(ll num)
{
	if (num >= 4999)
		return ;
	DP[num + 2] = ((DP[num] * 3 - 1) % 1000000007);
	rec(num + 2);
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> T;
	DP[2] = 1;
	rec(2);
	for (int i = 0; i < T; i++)
	{
		ll L;
		cin >> L;
		cout << DP[L] << endl;
	}
		
}
