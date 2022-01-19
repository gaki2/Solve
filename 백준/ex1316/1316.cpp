#include <iostream>
using namespace std;

int		is_valid(string str)
{
	char	arr[256];
	int		index;
	char	c;

	index = 0;
	while (index < 256)
		arr[index++] = 0;
	index = 0;
	while (str[index])
	{
		if (!arr[(int)str[index]] && ('a' <= str[index] && str[index] <= 'z'))
		{
			c = str[index];
			arr[(int)str[index]] = 1; 
			while (c == str[index])
				index++;
		}
		else
			return (0);
	}
	return (1);
}

int		main(void)
{
	int		t;
	int		cnt;
	int		index;
	string	test;
	cin >> t;

	cnt = 0;
	index = 0;
	while (index < t)
	{
		cin >> test;
		if (is_valid(test))
			cnt++;
		index++;
	}
	cout << cnt << '\n';
	return (0);
}
