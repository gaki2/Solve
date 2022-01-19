#include <string>
#include <vector>
#include <queue>
using namespace std;

int watcher[360003];

int strToTime(string s)
{
    string hour;
    string min;
    string sec;

    hour = s.substr(0, 2);
    min = s.substr(3, 2);
    sec = s.substr(6, 2);

    int h = stoi(hour) * 3600;
    int m = stoi(min) * 60;
    int ss = stoi(sec);

    return (h + m + ss);
}

string timeToStr(int t)
{
    string ret = "";
    int s, m, h;
    s = t % 60;
    t /= 60;
    m = t % 60;
    t /= 60;
    h = t;

    if (h < 10)
        ret += "0";
    ret += to_string(h);
    ret += ":";
    if (m < 10)
        ret += "0";
    ret += to_string(m);
    ret += ":";
    if (s < 10)
        ret += "0";
    ret += to_string(s);

    return (ret);
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";
    int playTime = 0;
    int adTime = 0;

    for (int i = 0; i != logs.size(); i++)
    {
        string log = logs[i];
        int begin;
        int end;
        begin = strToTime(log.substr(0, 8));
        end = strToTime(log.substr(9, 8));
        for (int j = begin; j != end; j++)
        {
            watcher[j]++;
        }
    }

    playTime = strToTime(play_time);
    adTime = strToTime(adv_time);
    int maxWatcher = 0;
    int watchNum = 0;
    int idx = 0;
    queue<int> q;

    for (int k = 0; k < adTime; k++)
    {
        watchNum += watcher[k];
        q.push(k);
    }
    maxWatcher = watchNum;
    idx = 0;

    for (int i = adTime; i < playTime; i++)
    {
        watchNum -= watcher[q.front()];
        q.pop();
        watchNum += watcher[i];
        q.push(i);
        if (maxWatcher < watchNum)
        {
            maxWatcher = watchNum;
            idx = q.front();
        }
    }

    return timeToStr(idx);
}