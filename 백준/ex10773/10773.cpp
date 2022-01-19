#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int			t;
	cin >> t;
	vector<int> value(t);
	int			index;
	int			target;
	long long	sum;

	sum = 0;
	index = 0;
	target = 0;
	while (index < t)
	{
		cin >> value[target];
		if (value[target] == 0)
		{
			value[target - 1] = 0;
			target--;
		}
		else
			target++;
		index++;
	}

	for (index = 0; index < t; index++)
		sum += value[index];
	cout << sum;
	return (0);
}
	
