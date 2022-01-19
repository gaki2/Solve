#include <iostream>
#include <vector>
#include <string>

char	arr[101] = {'0',};

int		main(void)
{
	int		index;

	string set;
	cin >> set;
	index = 0;
	for (int i = 0; i < set.length(); i++)
	{
		if (set[i] == '(')
		{
			arr[index] = i;
			index++;
		}
		if (set[i] == ')')
		{
			arr[index] = i;
			for (int j = arr[index - 1]; j <;
			
		

