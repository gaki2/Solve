//저울
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		N;
vector<int> w;

int		main(void)
{
	int		temp;
	int		sum;

	sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		w.push_back(temp);
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < N; i++)
	{
		if (sum + 1 < w[i])
			break;
		sum += w[i];
	}
	printf("%d", sum + 1);
	return (0);
}
