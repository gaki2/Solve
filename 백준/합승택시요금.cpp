#include <string>
#include <vector>

using namespace std;

int node[201][201];
#define INF 987654321

void init()
{
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            if (i == j)
            {
                node[i][j] = 0;
            }
            else
            {
                node[i][j] = INF;
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    init();

    for (int i = 0; i != fares.size(); i++)
    {
        node[fares[i][0]][fares[i][1]] = fares[i][2];
        node[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                node[j][k] = min(node[j][k], node[j][i] + node[i][k]);
            }
        }
    }

    int answer = INF;

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, node[s][i] + node[i][a] + node[i][b]);
    }

    return answer;
}