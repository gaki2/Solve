#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int		N;

typedef struct fibo
{
	int		zero_cnt;
	int		one_cnt;
} FIBO;

FIBO arr[41] = { {0,0}, };

FIBO	count(int n)
{
	FIBO temp, temp2;
	if (arr[n].zero_cnt == 0 && arr[n].one_cnt == 0)
	{
		temp = count(n - 1);
		temp2 = count(n - 2);
		arr[n].zero_cnt += temp.zero_cnt + temp2.zero_cnt;
		arr[n].one_cnt += temp.one_cnt + temp2.one_cnt;
	}
	return (arr[n]);
}

int		main(void)
{
	cin >> N;
	arr[0].zero_cnt = 1;
	arr[0].one_cnt = 0;
	arr[1].zero_cnt = 0;
	arr[1].one_cnt = 1;
	for (int i = 0; i < N; i++)
	{
		int		num;
		cin >> num;
		count(num);
		printf("%d %d\n", arr[num].zero_cnt, arr[num].one_cnt);
	}
	return (0);
}
