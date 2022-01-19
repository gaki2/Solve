#include <iostream>
using namespace std;

bool is_pallindromNum(string testcase)
{
	int len = testcase.size();
	int i = 0;
	while (i < len / 2)
	{
		if (testcase[i] == testcase[len - 1 - i])
		{
			i++;
			continue;
		}
		else
			return (false);
	}
	return (true);
}

int main(void)
{
	ios::sync_with_stdio(0);

	while (1)
	{
		string a;
		cin >> a;
		if (a == "0")
			break;
		if (is_pallindromNum(a))
		{
			cout << "yes" << '\n';
		}
		else
			cout << "no" << '\n';
	}
}
