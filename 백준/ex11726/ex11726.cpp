#include <iostream>

using namespace std;

long long arr[1000][2] = { {1,0}, {1,1}};
int		N;

int		main(void)
{
	cin >> N;
	for (int i = 2; i < 1000; i++)
	{
		arr[i][0] = (arr[i - 1][0] + arr[i - 2][0]) % 10007;
		arr[i][1] = (arr[i - 1][1] + arr[i - 2][1]) % 10007;
	}
	printf("%lld\n", (arr[N - 1][0] + arr[N - 1][1]) % 10007);
	return (0);
}

