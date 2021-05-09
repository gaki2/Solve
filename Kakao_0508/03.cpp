#include <string>
#include <vector>
#include <stack>
#include <string.h>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> s;
    int stack_arr[n];
    for (int i =0; i < n; i++)
    {
        stack_arr[i] = 0;
    }
    string answer = "";

    int pointer = k;
    int num_ele = n;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'U')
        {
            int u_moves = (int)(cmd[i][2] - 48);
            while (u_moves)
            {
                pointer--;
                if (stack_arr[pointer])
                    continue;
                else
                    u_moves--;
            }
            cout << "pointer: " << pointer << endl;
        }
        else if (cmd[i][0] == 'D')
        {
            int d_moves = (int)(cmd[i][2] - 48);
            while (d_moves)
            {
                pointer++;
                if (stack_arr[pointer])
                    continue;
                else
                    d_moves--;
            }    
        }
        else if (cmd[i][0] == 'C')
        {
            bool flag = false;
            for (int j = pointer + 1; j < n; j++)
            {
                if (stack_arr[j] != 1){
                    flag = true;
                }
            }
            if (!flag)
            {
                s.push(pointer);
                stack_arr[pointer] = 1;
                pointer--;
                cout << "check";
            }
            else if (flag)
            {
                s.push(pointer);
                stack_arr[pointer] = 1;
                pointer++;
            }
        }
        else {
            int temp = s.top();
            s.pop();
            stack_arr[temp] = 0;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (stack_arr[j] == 1)
        {
            answer.push_back('X');
        }
        else
            answer.push_back('O');
    }
    return answer;
}

int main()
{
    vector<string> cmd;
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 4");
    cmd.push_back("C");
    cmd.push_back("U 2");
    cmd.push_back("Z");
    cmd.push_back("Z");
    cmd.push_back("U 1");
    cmd.push_back("C");
    cout << solution(8, 2, cmd);
}