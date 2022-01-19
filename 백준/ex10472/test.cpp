#include <iostream>
#include <vector>
using namespace std;

int		main(void)
{
	vector<vector<int> > a;
	a.push_back({1,2,3});
	a.push_back({3,4,5,6,7});
	for(auto q: a)
		for(auto k: q)
			cout << k << endl;
}
