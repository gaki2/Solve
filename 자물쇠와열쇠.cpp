#include <string>
#include <vector>

using namespace std;
vector<vector<int>> Key;
vector<vector<int>> Board;

vector<vector<int>> flip(vector<vector<int>> key)
{
    vector<vector<int>> temp;

    int idx = key.size() - 1;
    for (int i = key.size() - 1; i != -1; i--)
    {
        temp.push_back(key[i]);
    }

    return temp;
}

void rotate90()
{
    vector<vector<int>> temp = Key;

    int max_idx = Key.size() - 1;

    for (int i = 0; i < Key.size(); i++)
    {
        for (int j = 0; j < Key.size(); j++)
        {
            temp[j][max_idx - i] = Key[i][j];
        }
    }
    Key = temp;
}

bool check(int row, int col, int width, int keySize, int hole)
{
    int cnt = 0;
    for (int k = 0; k < keySize; k++)
    {
        for (int l = 0; l < keySize; l++)
        {
            if (row + k >= width || col + l >= width)
                break;
            if (Board[row + k][col + l] == Key[k][l])
                return false;
            if (Board[row + k][col + l] != Key[k][l])
                cnt++;
        }
    }
    if (cnt == hole)
        return true;
    else
        return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{

    int width = lock.size();
    int keySize = key.size();
    int hole = 0;

    Key = flip(key);
    Board = lock;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (Board[i][j] == 0)
                hole++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        rotate90();
        for (int k = 0; k < width; k++)
        {
            for (int l = 0; l < width; l++)
            {
                if (check(k, l, width, keySize, hole))
                    return true;
            }
        }
    }
    return false;
}