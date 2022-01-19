#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int		H,W;
vector <int> heights;
int		S;

int		find_max_idx(int start_idx)
{
	int	max_idx = (max_element(heights.begin()+start_idx, heights.end()) - heights.begin());
	return (max_idx);
}

int		find_standard(int start_idx)
{
	for (int i = start_idx; i < W - 1; i++)
	{
		if (heights[i] > heights[i+1])
			return (i);
	}
	return (-1);
}

void	add_s(int start, int finish, bool is_overed)
{
	int		height = is_overed ? heights[start] : heights[finish];
	for (int i = start + 1; i < finish; i++)
	{
		S += (height - heights[i]);
	}
}

void	exe(int start_idx)
{
	int		start_point;
	int		max_idx;

	start_point = find_standard(start_idx);
	if (start_point == -1 || start_point == W - 2)
		return ;
	max_idx = find_max_idx(start_point + 1);
	
	if (heights[start_point] <= heights[max_idx])
	{
		for (int i = start_point + 1; i < max_idx; i++)
		{
			//여기 if 문을 생각해냈어야댐 !! 
			if (heights[start_point] <= heights[i])
			{
				max_idx = i;
				break ;
			}
		}
		add_s(start_point, max_idx, true);
	}
	else if (heights[start_point] > heights[max_idx])
	{
		add_s(start_point, max_idx, false);
	}
	exe(max_idx);
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> H >> W;
	for (int i = 0; i < W; i++)
	{
		int		height;
		cin >> height;
		heights.push_back(height);
	}
	exe(0);
	cout << S << endl;
}
