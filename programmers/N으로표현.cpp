//#include <iostream>

#include <string>
#include <vector>
#include <cmath>
using namespace std;
int is_double[32001];
vector<int> DP;
int start_idx = 0;
int g_result = 0;

void _init(int N)
{
	DP.push_back(N);
	is_double[N] = 1;
}

int iter(int row, int N)
{
	int result = 0;

	for (int i = row - 1; i > 0; i--)
	{
		result += (N * pow(10, i));
	}
	result += N;
	return (result);
}


void Fill_DP(int row, int N, int Number)
{
	int start = start_idx;
	int end = DP.size();
	for (int j = start; j != end; j++)
	{
		if (DP[j] == Number)
		{
			g_result = row - 1;
			return ;
		}
	}
	if (row > 8)
		return ;
	if (iter(row, N) < 32001)
	{
		DP.push_back(iter(row, N));
		is_double[iter(row, N)] = 1;
	}
	for (int i = start; i != end; i++)
	{
		if (DP[i] + N < 32001 && !is_double[DP[i] + N]) 
		{
			DP.push_back(DP[i] + N);
			is_double[DP[i] + N] = 1;
		}
		if (DP[i] * N < 32001 && !is_double[DP[i] * N]) 
		{
			DP.push_back(DP[i] * N);
			is_double[DP[i] * N] = 1;
		}
		if (DP[i] - N > 0 && !is_double[DP[i] - N]) 
		{
			DP.push_back(DP[i] - N);
			is_double[DP[i] - N] = 1;
		}

		if (!is_double[DP[i] / N])
		{
			DP.push_back(DP[i] / N);
			is_double[DP[i] / N] = 1;
		}
	}
	start_idx = end;
	Fill_DP(row + 1, N, Number);
}

int solution(int N, int number) {
    int answer = 0;
	_init(N);
	Fill_DP(2, N, number);
	answer = g_result > 0 ? g_result : -1;
    return answer;
}

int main(void)
{
	int N, number;
	cin >> N >> number;
	cout << solution(N, number) << '\n';
}
