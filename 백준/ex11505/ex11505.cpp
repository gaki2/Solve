#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int		N,M,K;
vector<ll> set;
vector<ll> tree;

ll		make_tree(int node, int	start, int end)
{
	if (start == end)
		return (tree[node] = set[start]);
	int		mid = (start + end) / 2;
	return (tree[node] = (make_tree(node * 2, start, mid) * make_tree(node * 2 + 1, mid + 1, end) % 1000000007));
}

ll		find_answer(int node, int start, int end, int go, int till)
{
	if (end < go || start > till)
		return (1);
	if (go <= start && end <= till)
		return (tree[node]);
	int		mid = (start + end) / 2;
	return ((find_answer(node * 2, start, mid, go, till) * find_answer(node * 2 + 1, mid + 1, end, go, till)) % 1000000007);
}

void	update(int node, int start, int end, int index, ll value)
{
	if (start > index || index > end)
		return ;
	if (start == end && start == index)
	{
		tree[node] = value;
		return ;
	}
	int		mid = (start + end) / 2;
	update(node * 2, start, mid, index, value);
	update(node * 2 + 1, mid + 1, end, index, value);
	tree[node] = ((tree[node * 2] * tree[node * 2 + 1]) % 1000000007);
}

int		main(void)
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		ll	temp;
		scanf("%lld", &temp);
		set.push_back(temp);
	}
	int		size = (1 << ((int)ceil(log2(N)) + 1));
	tree.resize(size, 1);
	make_tree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		int		option;
		scanf("%d", &option);
		if (option == 1)
		{
			int		index;
			ll		value;
			scanf("%d %lld", &index, &value);
			update(1, 0, N - 1, index - 1, value);
			set[index - 1] = value;
		}
		else if (option == 2)
		{
			int		go;
			int		till;
			scanf("%d %d", &go, &till);
			printf("%lld\n", find_answer(1, 0, N - 1, go - 1, till - 1));
		}
	}
	return (0);
}
