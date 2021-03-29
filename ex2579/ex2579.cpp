#include <iostream>
#include <algorithm>
using namespace std;

int		N;
int		map[304];
int		g_ret;

void	search(int index, int count, int ret)
{
	if (count == 3)	return ;
	if (index > N)	return ;
	if (index == N)	g_ret = max(g_ret, ret);

	search(index + 1, count + 1, ret + map[index + 1]);
	search(index + 2, 1, ret + map[index + 2]);
}

int		main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &map[i]);
	}
	search(0, 0, 0);
	printf("%d\n", g_ret);
}


#include<iostream>
 
#define endl "\n"
#define MAX 301
using namespace std;
 
int N;
int Arr[MAX];    // 계단을 나타내는 배열
int DP[MAX];    // 해당 계단까지의 Max값을 나타내는 배열
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
    }
}
 
void Solution()
{
    DP[1] = Arr[1];    // 첫 번째 계단까지의 Max 값은 첫번째 계단 값이지
    DP[2] = Arr[1] + Arr[2];
    DP[3] = Max(Arr[1] + Arr[3], Arr[2] + Arr[3]);
    
    for (int i = 4; i <= N; i++)
    {
        DP[i] = Max(DP[i - 2] + Arr[i], DP[i - 3] + Arr[i-1] + Arr[i]);
    }
 
    cout << DP[N] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
    
    return 0;
}
