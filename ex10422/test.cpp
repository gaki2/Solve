#include<iostream>
#include <string.h>
#include<string>
#include<queue>
#include <vector>
#include<map>

using namespace std;

long long D[5001];
void init()
{
	D[0] = 1;
	D[2] = 1;

	for (int i = 3; i <= 5000; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			D[i] += D[j - 2] * D[i - j];
		}
		D[i] %= 1000000007;
	}
}

int main(void)
{
	int tc;
	cin >> tc;
	
	init();

	for (int t = 0; t < tc; t++)
	{
		int n;
		cin >> n;
		cout << D[n] << endl;
	}
}
