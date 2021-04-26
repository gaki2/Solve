#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //make queue
    priority_queue<int, vector<int>, greater<int>> greater_pq;
    priority_queue<int, vector<int>, less<int>> less_pq;

    int cnt = 0;

    for (int i = 0; i < operations.size(); ++i)
    {
        if (!cnt) 
        {
            while (!greater_pq.empty()) greater_pq.pop();
            while (!less_pq.empty()) less_pq.pop();
        }
        if (operations[i][0] == 'I')
        {
            string temp = operations[i].substr(2);
            int value = stoi(temp);
            greater_pq.push(value);
            less_pq.push(value);
            cnt++;
        }   

        else if (operations[i][0] == 'D')
        { 
            if (!cnt) continue;  
            string temp = operations[i].substr(2);
            int value = stoi(temp);
            if (value == 1)
            {
                less_pq.pop();
                cnt--;
            }
            else
            {
                greater_pq.pop();
                cnt--;
            }
                
        }
    }
    if (cnt) {
        answer[0] = less_pq.top();
        answer[1] = greater_pq.top();
    }
    return answer;
}

