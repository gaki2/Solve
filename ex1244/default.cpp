#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int		N; // Num of Switches
int		M; // Num of Students
int		s[101];

void	toggle(int idx)
{
	if (s[idx])
		s[idx] = 0;
	else
		s[idx] = 1;
}

void	Male(int n)
{
	int		original = n;

	while (n <= N) {
		toggle(n - 1);
		n += original;
	}
}

void	Female(int n)
{
	int		before;
	int		next;
	int		i;

	i = 1;
	toggle(n - 1); // 처음 n 하나에 대해서 변경
	while (1)
	{
		before = n - i;
		next = n + i;
		if ((before >= 1) && (next <= N) && (s[before - 1] == s[next - 1])) // before,next 가 범위에있는지, 두 스위치의 상태가 같은지 확인
		{
			toggle(before - 1);
			toggle(next - 1);
			i++;
		}
		else
			break ;
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int		sex;
		int		idx;
		cin >> sex >> idx;
		if (sex == 1)
		{
			Male(idx);
		}
		else
		{
			Female(idx);
		}
	}
	int coutcnt = 0;

	for (int i = 0; i < N; i++)
	{
		cout << s[i] << ' ';
		coutcnt++;
		if (coutcnt % 20 == 0)
			cout << '\n';
	}
}
