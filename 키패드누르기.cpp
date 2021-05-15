#include <string>
#include <vector>

using namespace std;

void    renewLPosition(int arr[4][3], int NUM)
{
    
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int     position[4][3] = {0,};
    int     L_DIST;
    int     R_DIST;

    for (int i = 0; i < numbers.size(); i++)
    {
        int now_button = numbers[i];
        if (now_button == 1 || now_button == 4 || now_button == 7) {
            renewLPosition()
        }
        else if (now_button == 3 || now_button == 6 || now_button == 9) {
            renewRPosition();
        }
        else {
            L_DIST = 번호 - 1 % 3 으로 좌표계산
        }
    }



    return answer;
}