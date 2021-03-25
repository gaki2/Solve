#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector <pair<int, int> > segmenttree;
vector <int> arr;
int		N;
int		M;

pair<int, int>	find(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)	return make_pair(1000000000,1);
	if (left <= start && end <= right)	return segmenttree[node];

	int		mid = (start + end) / 2;
	pair<int, int>left_result = find(node * 2, start, mid, left, right);
	pair<int, int>right_result = find(node * 2 + 1, mid + 1, end, left, right);
	int		Min = min(left_result.first, right_result.first);
	int		Max = max(left_result.second, right_result.second);
	return (make_pair(Min, Max));
}

pair<int, int>	Make_segmenttree(int node, int start, int end)
{
	if (start == end)
	{
		int		Max = arr[start];
		int		Min = arr[start];
		segmenttree[node] = (make_pair(Min, Max));
		return (segmenttree[node]);
	}

	int		mid = (start + end) / 2;
	pair<int, int>	left_result = Make_segmenttree(node * 2, start, mid);
	pair<int, int>	right_result = Make_segmenttree(node * 2 + 1, mid + 1, end);
	int		Min = min(left_result.first, right_result.first);
	int		Max = max(left_result.second, right_result.second);
	segmenttree[node] = (make_pair(Min,Max));
	return (segmenttree[node]);
}

int		main(void)
{
	vector<pair<int, int> > temp2;
	cin >> N >> M;
	int		temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	int		tree_height = (int)ceil(log2(N));
	int		tree_size = (1 << (tree_height + 1));
	segmenttree.resize(tree_size);
	Make_segmenttree(1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		int		start;
		int		end;
		pair<int, int> ret2;
		cin >> start >> end;
		ret2 = find(1, 0, N - 1, start - 1, end - 1);
		temp2.push_back(ret2);
	}
	for (int i = 0; i < M; i++)
	{
		printf("%d %d\n", temp2[i].first, temp2[i].second);
	}
	return (0);
}
