#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int		n;
	cin >> n;
	int		index;
	vector<int> order(n, 1);
	int		jdex;

	index = 0;
	pair <int, int> mass[n];
	while (index < n)
	{
		cin >> mass[index].first;
		cin >> mass[index].second;
		index++;
	}
	for (index = 0; index < n; index++)
	{
		for (jdex = 0; jdex < n; jdex++)
		{
			if (mass[index].first < mass[jdex].first && mass[index].second < mass[jdex].second)
				order[index]++;
		}
	}
	for (index = 0; index < n; index++)
		cout << order[index] << ' ';
	return (0);
}



