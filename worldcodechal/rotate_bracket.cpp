#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
	stack<char> s1;

	for (int j = 0; j < s.size(); j++)
	{
		if (j)
		{
			char temp = *(s.begin());
			s.erase(s.begin());
			s += temp;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')')
			{
				s1.front() == '(' ? s1.pop() : break ;
			}
			else if (s[i] == '}')
			{
				s1.front() == '{' ? s1.pop() : break ;
			}
			else if (s[i] == ']')
			{
				s1.front() == '[' ? s1.pop() : break ;
			}
			else
				s1.push(s[i]);
		}
			if (i == s.size() && s.empty())
				answer++;
	}
    return answer;
} 
