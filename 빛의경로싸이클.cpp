#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct s_point
{
    int row;
    int col;
    int di;
    int cnt;
};
int visited[501][501][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
vector<string> Board;
vector<int> answer;

s_point changeDi(s_point now)
{
    int now_row = now.row;
    int now_col = now.col;
    int now_di = now.di;
    s_point ret;

    int new_row = now_row + dy[now_di];
    int new_col = now_col + dx[now_di];

    if (new_row < 0)
        new_row = n - 1;
    else if (new_row > n - 1)
        new_row = 0;
    if (new_col < 0)
        new_col = m - 1;
    else if (new_col > m - 1)
        new_col = 0;

    char direction = Board[new_row][new_col];
    ret.row = new_row;
    ret.col = new_col;
    ret.cnt = now.cnt + 1;

    if (direction == 'S')
    {
        ret.di = now_di;
        return (ret);
    }
    else if (direction == 'L')
    {
        if (now_di == 0)
            now_di = 2;
        else if (now_di == 1)
            now_di = 3;
        else if (now_di == 2)
            now_di = 1;
        else
            now_di = 0;
        ret.di = now_di;
        return (ret);
    }
    else
    {
        if (now_di == 0)
            now_di = 3;
        else if (now_di == 1)
            now_di = 2;
        else if (now_di == 2)
            now_di = 0;
        else
            now_di = 1;
        ret.di = now_di;
        return (ret);
    }
}

void cycle(s_point s, s_point now)
{
    int now_row = now.row;
    int now_col = now.col;
    int now_di = now.di;

        s_point temp = changeDi(now);
    if (visited[temp.row][temp.col][temp.di] == 1)
        return;
    visited[temp.row][temp.col][temp.di] = 1;
    // cout << "s "<< s.row << " " << s.col << " " << s.di << endl;
    // cout << "temp "<< temp.row << " " << temp.col << " " << temp.di << endl;
    if (temp.row == s.row && temp.col == s.col && temp.di == s.di)
    {
        answer.push_back(temp.cnt);
        return;
    }
    cycle(s, temp);
}

vector<int> solution(vector<string> grid)
{
    n = grid.size();
    m = grid[0].length();
    Board = grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                s_point s = {i, j, k, 0};
                s_point now = {i, j, k, 0};
                cycle(s, now);
            }
        }
    }
    return answer;
}