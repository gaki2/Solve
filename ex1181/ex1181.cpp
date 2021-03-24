#include <iostream>
#include <vector>
#include <string> 
#include <algorithm> // sort 함수가 있음
#include <cstring>
using namespace std;

int		N;

bool	tool(string a, string b)
{
	if (a.length() == b.length())
		return (strcmp(a.c_str(), b.c_str()) < 0);
	else
		return (a.length() < b.length());
}

int		main(void)
{
	cin >> N;
	string	word;
	vector<string> words;

	for (int i = 0; i < N; i++)
	{
		cin >> word;
		if (find(words.begin(), words.end(), word) == words.end())
			words.push_back(word);
	}
	sort(words.begin(), words.end(), tool);
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << '\n';
	return (0);
}
