#include <iostream>
using namespace std;

int		main(void)
{
	int		days;
	int		units;
	int		my_days;
	int		index;
	int		result;

	index = 1;
	while (1)
	{
		cin >> days;
		cin >> units;
		cin >> my_days;
		if (days == units && my_days == 0 && my_days == days)
			break;
		if ((my_days % units) <= days)
			result = (my_days / units) * days + (my_days % units);
		else 
			result = (my_days / units) * days + days;
		printf("Case %d: %d\n", index, result);
		index++;
	}
	return (0);
}
