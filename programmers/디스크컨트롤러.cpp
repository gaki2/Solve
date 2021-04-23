#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct compare{
    bool operator()(pair<int,int>a, pair<int,int>b)
    {
        return a.second < b.second;
    }
}

bool firstcompare(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return (true);
    if (a[0] == b[0] && a[1] < b[1])
        return (true);
    return (false);
}

int solution(vector<vector<int>> jobs) {

    int answer = 0;
    int now_time = 0;
    int i = 0;
    sort(jobs.begin(), jobs.end(), firstcompare);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
    
    int f,s;
    f = jobs[i][0];
    s = jobs[i][1];
    pq.push(make_pair(f,s));
    jobs.erase(jobs.begin());

    while (!jobs.size())
    {
           

    }
    return answer;
