#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> m;
    string answer = "";
    for (string s : participant)
    {
        if (m.find(s) == m.end())
        {
            m[s] = 1;
        }
        else
        {
            m[s]++;
        }
    }

    for (string s : completion)
    {
        m[s]--;
    }

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second != 0)
        {
            answer = iter->first;
            break;
        }
    }

    return answer;
}