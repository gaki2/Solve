#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int		set[100001];
int		N;
int		result = 0;
vector<int> tree;

int		make_tree(int node, int start, int end)
{
	if (start == end) return (tree[node] = start);
	int mid = (start + end) / 2;
	int	left = make_tree(node * 2, start, mid);
	int	right = make_tree(node * 2 + 1, mid + 1, end);

	return (tree[node] = set[left] < set[right] ? left : right);
}

int		find_min(int node, int start, int end, int go, int till)
{
	if (end < go || till < start) return (100000);
	if (go <= start && end <= till) return (tree[node]);
	int	mid = (start + end) / 2;
	int	left = find_min(node * 2, start, mid, go, till);
	int	right = find_min(node * 2 + 1, mid + 1, end, go, till);
	return (set[left] < set[right] ? left : right);
}

void	div_con(int start, int end)
{
	if (start > end)	return ;

	int	h = find_min(1, 0, N - 1, start, end);
	result = max(result, set[h] * (end - start + 1));
	div_con(start, h - 1);
	div_con(h + 1, end);
}

int	main(void)
{
	scanf("%d", &N);
	set[100000] = 2100000000;
	for (int i = 0; i < N; i++)
	{
		int		height;
		scanf("%d", &height);
		set[i] = height;
	}
	tree.resize(N * 4);
	make_tree(1, 0, N - 1);
	div_con(0, N - 1);
	printf("%d\n", result);
	return (0);
}

