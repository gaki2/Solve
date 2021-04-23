#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    //push 
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    // ⬆️ same as : priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
    while (1)
    {   //check
        if (pq.top() >= K)
        break;
        //finish exeception
        if (pq.size() == 1 && pq.top() < K)
        {
            answer = -1;
            break;
        }
        //mix
        int lowest = pq.top();
        pq.pop();
        int next_lowest = pq.top();
        pq.pop();
        int new_scoville = lowest + next_lowest*2;
        pq.push(new_scoville);
        answer++;
    }
    return answer;
}