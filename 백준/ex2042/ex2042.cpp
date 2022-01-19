#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
//typedef long long	ll;
#define ll long long
using namespace std;

int N, M, K;
vector<ll> set;
vector<ll> tree;
//틀린이유: tree size 잴 때(1 << (int)ceil(log2(N)) + 1) 인데 맨 뒤에 +1 빼먹음 ..
void	change(int index, ll diff) //인덱스 트리 방법으로 하면 수정이 많을때 편함.
{
	while (index > 0)
	{
		tree[index] += diff;
		index /= 2;
	}
}

ll		find_sum(int node, int start, int end, int go, int till)
{
	if (start > till || go > end)
		return (0);
	if (go <= start && till >= end)
		return (tree[node]);
	int		mid = (start + end) / 2;
	ll		left = find_sum(node * 2, start, mid, go, till);
	ll		right = find_sum(node * 2 + 1, mid + 1, end, go, till);
	return (left + right);
}

ll		make_tree(int node, int start, int end)
{
	if (start == end)
		return (tree[node] = set[start]);
	int		mid = (start + end) / 2;
	ll		left = make_tree(node * 2, start, mid);
	ll		right = make_tree(node * 2 + 1, mid + 1, end);
	return (tree[node] = left + right);
}

int		main(void)
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		ll		temp;
		cin >> temp;
		set.push_back(temp);
	}
	int		size = (1 << (int)(ceil(log2(N)) + 1));
	tree.resize(size);
	make_tree(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int		option;
		scanf("%d", &option);
		if (option == 1)
		{
			int		go;
			ll		till;
			scanf("%d %lld", &go, &till);
			ll	diff = till - set[go - 1];
			set[go - 1] = till;
			change(1, 0, N - 1, go - 1, diff);
		}
		else if (option == 2)
		{
			int		go, till;
			scanf("%d %d", &go, &till);
			printf("%lld\n", find_sum(1, 0, N - 1, go - 1, till - 1));
		}
	}
	return (0);
}
