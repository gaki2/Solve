#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> h;
vector<int> tree;
int		MAXS = 0;

int		makeTree(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = h[start];
		return (tree[node]); // 트리의 가장 맨 아래쪽 , value : 히스토그램 높이
	}

	int		mid = (start + end) / 2;
	int		left = makeTree(node * 2, start, mid);
	int		right = makeTree(node * 2 + 1, mid + 1, end);
	return (tree[node] = left > right ? right : left); // 두개의 자식 노드의 최소값이 부모노드로 감
}

int		findMinH(int node, int begin, int finish, int start, int end)
{
	if (start <= begin && finish <= end)
		return (tree[node]); // 해당 범위안에 찾으려는 범위가 포함되면 그 노드를 리턴
	if (start > finish || end < begin)
		return (2100);	// 그렇지 않으면 존나 큰 수를 리턴

	int		mid = (begin + finish) / 2;
	int		left = findMinH(node * 2, begin, mid, start, end);
	int		right = findMinH(node * 2 + 1, mid + 1, finish, start, end);
	return (left < right ? left : right); // left, right 중 더 작은 노드의 값을 리턴함 결과적으로 범위내의 
	//최소높이가 리턴됨
}

void	findMaxS(int start, int end, int N)
{
	if (start > end)
		return ;
	else
	{
		int		min_h = findMinH(1, 0, N-1, start, end);
		MAXS = max(MAXS, min_h * (end - start + 1));
		int		min_idx = (find(h.begin() + start, h.begin() + end, min_h)) - h.begin();
		findMaxS(start, min_idx - 1, N);
		findMaxS(min_idx + 1, end, N);
	}
}

int		main(void)
{
	ios::sync_with_stdio(0);
	int		N;

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		h.push_back(M);
	}
	//makeTree
	int height = (1 << (int)(ceil(log2(N) + 1)));
	tree.resize(height); // 미리 resize 를 해주면 tree가 커짐에따라 re capitalize 하는 과정이 사라져서 더 빨라짐.
	makeTree(1, 0, N-1);
	findMaxS(0, N-1, N);
	cout << MAXS << endl;
}
