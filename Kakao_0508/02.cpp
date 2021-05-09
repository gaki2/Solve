#include <string>
#include <vector>

using namespace std;

int x_move[8] = {-2,2,0,0,1,1,-1,-1};
int y_move[8] = {0,0,2,-2,-1,1,1,-1};

int x_move2[4] = {0,0,1,-1};
int y_move2[4] = {1,-1,0,0};

bool    is_valid_pos(int row, int col, vector<string> place)
{
    for (int i = 0; i < 4; i++)
    {
        int d_row = row + y_move2[i];
        int d_col = col + x_move2[i];
        if (d_row < 0 || d_row > 4 || d_col < 0 || d_col > 4)
            continue;
        if (place[d_row][d_col] == 'P')
            return (false); 
    }

    for (int i = 0; i < 8; i++)
    {
        int d_row = row + y_move[i];
        int d_col = col + x_move[i];
        if (d_row < 0 || d_row > 4 || d_col < 0 || d_col > 4)
            continue;
        if (place[d_row][d_col] == 'P')
        {
            if (0 <= i && i <= 3)
            {
                int mid_row = (row + d_row) / 2;
                int mid_col = (col + d_col) / 2;
                if (place[mid_row][mid_col] != 'X')
                    return (false);
            }
            else
            {
                int mid_row1 = (row);
                int mid_col1 = d_col;
                int mid_row2 = (d_row);
                int mid_col2 = col;
                if (place[mid_row1][mid_col1] != 'X' || place[mid_row2][mid_col2] != 'X')
                    return (false);
            }
        }
    }
        
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool breaker = false;

    for (int i = 0; i < 5; i++)
    {
        vector<string> place = places[i];
        breaker = false;
        for (int j = 0; j < 5; j++)
        {
            if (breaker)
                break ;
            for (int z= 0; z < 5; z++)
            {
                if (place[j][z] == 'P')
                {
                    if (!is_valid_pos(j,z,place))
                    {
                        breaker = true;
                        answer[i] = 0;
                        break ;
                    }
                }
            }
        }
        answer[i] = 1;
    }
    return answer;
}