#include <iostream>
#include <vector>
#include <queue>
#define Max_value 101
using namespace std;

struct Pos{
    int y, x;
};

struct Dir{
    int t;
    char d;
};

struct Joint{
    int y;
    int x;
    int d;
};

int map[Max_value][Max_value] = {0,};
int x_move[4] = {1,0,-1,0};
int y_move[4] = {0,1,0,-1};
int N, M;
queue<Dir> dir;

void    Input()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    while (M--)
    {
        int y;
        int x;
        cin >> y >> x;
        map[y][x] = 2;
    }
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        char d;
        cin >> t >> d;
        dir.push({t,d});
    }
}

int TurnRight(int d)
{
    d += 1;
    d = d > 3 ? d - 4 : d;
    return (d);
}

int TurnLeft(int d)
{
    d -= 1;
    d = d < 0 ? d + 4 : d;
    return (d);
}

bool Is_end(int x, int y)
{
    if (x <= 0 || x > N || y <= 0 || y > N)
    {
        return (true);
    }
    if (map[y][x] == 1)
    {
        return (true);
    }
    return (false);
}

int Solve()
{
    map[1][1] = 1;
    int t = 0;
    int head_dir = 0;
    int tail_dir = 0;
    Pos head = {1,1}, tail = {1,1};
    queue<Joint> joint;
    while (1)
    {
        t++;
        head.x += x_move[head_dir];
        head.y += y_move[head_dir];
        
        if (Is_end(head.x,head.y))
        {
            break;
        }
		
		if (!joint.empty() && joint.front().x == tail.x && joint.front().y == tail.y)
        {
            tail_dir = joint.front().d;
            joint.pop();
        }

        if (map[head.y][head.x] != 2) 
        {
			map[tail.y][tail.x] = 0;
            tail.y += y_move[tail_dir];
            tail.x += x_move[tail_dir];
        }
		
		map[head.y][head.x] = 1;

        if (!dir.empty() && t == dir.front().t)
        {
            if (dir.front().d == 'D')
            {
                head_dir = TurnRight(head_dir);
                joint.push({head.y, head.x, head_dir});
            }
            else
            {
                head_dir = TurnLeft(head_dir);
                joint.push({head.y, head.x, head_dir});
            }
            dir.pop();
        }
    }
    return (t);
}

int     main(void)
{
    Input();
    cout << Solve() << '\n';
    return (0);
}
