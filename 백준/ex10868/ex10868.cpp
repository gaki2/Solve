#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int		N;
int		M;
vector<int>	set;
vector<int> tree;
vector<int> result;

int		find_min(int node, int start, int end, int go, int till)
{
	int		left;
	int		right;
	int		mid;

	if (go > end || till < start)
		return (1000000001);
	if (go <= start && till >= end)
		return (tree[node]);
	mid = (start + end) / 2;
	left = find_min(node * 2, start, mid, go, till);
	right = find_min(node * 2 + 1, mid + 1, end, go, till);
	return (min(left, right));
}

int		make_tree(int node, int start, int end)
{
	int		mid;
	int		left;
	int		right;

	if (start == end)
		return (tree[node] = set[start]);
	mid = (start + end) / 2;
	left = make_tree(node * 2, start, mid);
	right = make_tree(node * 2 + 1, mid + 1, end);
	return (tree[node] = min(left, right));
}

int		main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int		temp;
		cin >> temp;
		set.push_back(temp);
	}
	int		size = (1 << ((int)ceil(log2(N)) + 1));
	tree.resize(size);
	make_tree(1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		int		go;
		int		till;
		int		c;
		cin >> go >> till;
		c = find_min(1, 0, N - 1, go - 1, till - 1);
		result.push_back(c);
	}
	for (auto i : result)
		printf("%d\n", i);
	return (0);
}
