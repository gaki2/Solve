#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int		g_max_price;
int		n;
vector <pair<int, int> > g_info;

void	rec(int now_day, int count, int recent_add)
{
	if (now_day > n)
	{
		g_max_price = max(count - recent_add, g_max_price);
		return ;
	}
	else if (now_day == n)
	{
		g_max_price = max(count, g_max_price);
		return ;
	}
	while (now_day < n)
	{
		rec(now_day + g_info[now_day].first, count + g_info[now_day].second,
				g_info[now_day].second);
		now_day++;
	}
}

int		main(void)
{
	int						index;
	cin >>	n;
	pair<int, int>			time_price;

	g_max_price = 0;
	for (index = 0; index < n; index++)
	{
		cin >> time_price.first >> time_price.second;
		g_info.push_back(time_price);
	}
	for (index = 0; index < n; index++)
	{
			rec(index + g_info[index].first, g_info[index].second, g_info[index].second);
	}
	cout << g_max_price << '\n';
	return (0);
}





