#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

int		main(void)
{
	vector<string> v;
	vector<string> v2;
	string a;

	cin >> a;
	v.push_back(a);
	v2 = v;
	v2[0][0] = 'z';
	v2[0][1] = 'o';
	cout << v[0] << '\n';
	cout << v2[0] << '\n';
	return (0);
}

