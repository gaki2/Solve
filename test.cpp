#include <iostream>
using namespace std;

void    ssss(int arr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = 2;
        }
    }
}

int     main()
{
    int arr[4][4] = {0,};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << endl;
        }
    }
}