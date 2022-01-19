#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
vector<string> NEWMAP;
vector<string> MAP;
int		T;

int		isCluster(void) // 첫번째 줄에서 두개 혹은 세게연속으로 newmap , map 의 다른블럭이 붙어있을때
{
	int		count = 0;

	for (int i = 0; i < 3; i++)
	{
		if (MAP[0][i] != NEWMAP[0][i])
			count++;
	}
	
	if (count == 3)
		return (1);
	else if (count == 2)
	{
		if (MAP[0][1] == NEWMAP[0][1])
			return (-1);
		else if (MAP[0][0] != NEWMAP[0][0])
			return (0);
		else
			return (2);
	}
	else {
		return (-1);
	}
}


void	initMap(void)
{
	for (int i = 0; i < 3; i++)
		MAP.push_back("...");
}

void	clickBtn(int row, int col)
{
	int		x_move[5] = {0,1,-1,0,0};
	int		y_move[5] = {0,0,0,-1,1};

	
	for (int i = 0; i < 5; i++)
	{
		int nrow = row + x_move[i];
		int ncol = col + y_move[i];
		if (nrow < 0 || nrow >= 3 || ncol < 0 || ncol >= 3)
			continue ;
		if (MAP[nrow][ncol] == '*')
			MAP[nrow][ncol] = '.';
		else if (MAP[nrow][ncol] == '.')
			MAP[nrow][ncol] = '*';
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> T;
	int		count = 0;
	initMap();

	for (int k = 0; k < T; k++)
	{
		NEWMAP.clear();
		count = 0;
		for (int i = 0; i < 3; i++)
		{
			string line;
			cin >> line;
			NEWMAP.push_back(line);
		}
		for (int z = 0; z < 3; z++)
			for (int q = 0; q < 3; q++)
			{
				if (z == 0)
				{
					int idx = isCluster();
					if (idx != -1)
					{
						count++;
						clickBtn(0, idx);
					}
					break ;
				}
				if (MAP[z-1][q] != NEWMAP[z-1][q])
				{
					clickBtn(z,q);
					count++;
				}
			}
		cout << count << endl;
	}
}
