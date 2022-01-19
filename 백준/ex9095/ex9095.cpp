#include <iostream>
using namespace std;

int		arr[10][3] = {{1,0,0}, {1,1,0}};
int		N;
int		T;
int		main(void)
{
	
	for (int i = 2; i < 11; i++)
	{
		arr[i][0] = arr[i-1][0] + arr[i-1][1] + arr[i-1][2];
		arr[i][1] = arr[i-1][0]; 
		arr[i][2] = arr[i-1][1];
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		if (N == 1)
		{
			printf("%d\n", 1);
		}
		else
			printf("%d\n", 2 * arr[N - 2][0] + 2 * arr[N - 2][1] + arr[N - 2][2]);
	}
	return (0);
}

