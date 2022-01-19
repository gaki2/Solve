#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int		L;
int		C;
char	arr[16];
char	charset[16];
int		visit[16];
int		cnt;

void	rec(int index, int order)
{
	if (index == L)
	{
		cnt = 0;
		for (int j = 0; j < L; j++)
		{
			if(charset[j] == 'a' || charset[j] == 'i'|| charset[j] == 'o' || charset[j] == 'u' || charset[j] == 'e')
				cnt++;
		}
		if (cnt >= 1 && cnt <= L - 2)
			printf("%s\n", charset);
		return ;
	}

	for (int i = order; i < C; i++)
	{
		if (!visit[i])
		{
			charset[index] = arr[i];
			visit[i] = 1;
			rec(index + 1, i + 1);
			visit[i] = 0;
		}
	}
}

int		main(void)
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	arr[C] = 0;
	sort(arr, arr + C);
	rec(0, 0);
	return (0);
}