#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int		N,M;
int		dp[100][100];
int		cnt[100][100];

int		map[100][2];

int		main(void)
{
	cin >> N >> M;
	for (int i =0; i< N; i++)
	{
		scanf("%d",&map[i][0]);
		scanf("%d",&map[i][1]);
	}
	for (int i =0; i< N; i++)
	{
		cnt[0][i] = M;
	}




