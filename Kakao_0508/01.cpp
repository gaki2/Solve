#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string ret;
    for (int i = 0; i != s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            ret.push_back(s[i]);
            continue;   
        }
        else
        {
            if (s[i] == 'z')
            {
                ret.push_back('0');
                i = i + 3;
            }
            else if (s[i] == 'o')
            {
                ret.push_back('1');
                i = i + 2;
            }
            else if (s[i] == 't')
            {
                if (s[i + 1] == 'w')
                {
                    ret.push_back('2');
                    i = i + 2;
                }
                else
                {
                    ret.push_back('3');
                    i = i + 4;
                }
            }
            else if (s[i] == 'f')
            {
                if (s[i + 1] == 'o')
                {
                    ret.push_back('4');
                    i = i + 3;
                }
                else {
                    ret.push_back('5');
                    i = i + 3;
                }
            }
            else if (s[i] == 's')
            {
                if (s[i + 1] == 'i')
                {
                    ret.push_back('6');
                    i = i + 2;
                }
                else
                {
                    ret.push_back('7');
                    i = i + 4;
                }
            }
            else if (s[i] == 'e')
            {
                ret.push_back('8');
                i = i + 4;
            }
            else
            {
                ret.push_back('9');
                i = i + 3;
            }
        }
    }
	int answer;
    answer = stoi(ret);
    return answer;
}


