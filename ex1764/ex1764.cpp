#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int N, M;
using namespace std;
bool compare(string a, string b)
{
    if (a < b)
        return true;
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    vector<string> v1;
    vector<string> ret;
    for (int i = 0; i < N; i++)
    {
        string s1;
        cin >> s1;
        v1.push_back(s1);
    }
    
    for (int j = 0; j < M; j++)
    {
        string s2;
        cin >> s2;
        if (find(v1.begin(), v1.end(), s2) != v1.end())
        {
            ret.push_back(s2);
        }
    }

    sort(ret.begin(), ret.end(), compare);
    cout << ret.size() << '\n';
    vector<string>::iterator iter;
    for (iter = ret.begin(); iter != ret.end(); iter++)
    {
        cout << *iter << '\n';
    }
}
