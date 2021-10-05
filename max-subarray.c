#include <stdio.h>
#define INF -1234567890
#define max(a, b) (((a) > (b)) ? (a) : (b))
int array[100000];
int n;

int maxSum(int lo, int hi)
{
    if (lo == hi)
        return array[lo];

    int mid = (lo + hi) / 2;
    int left = INF;
    int right = INF;
    int sum = 0;

    for (int i = mid; i >= lo; i--)
    {
        sum += array[i];
        left = max(left, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= hi; i++)
    {
        sum += array[i];
        right = max(right, sum);
    }

    int ret = max(maxSum(lo, mid), maxSum(mid + 1, hi));
    return max(left + right, ret);
}

void findIndex()
{
    int curr_max = 0;
    int prev_max = 0;
    int start = 0;
    int end = 0;
    int start_o = 0;

    prev_max = array[0];

    for (int i = 0; i < n; i++)
    {
        curr_max += array[i];
        if (curr_max < 0)
        {
            start = i + 1;
            curr_max = 0;
        }
        else if (curr_max > prev_max)
        {
            end = i;
            start_o = start;
            prev_max = curr_max;
        }
    }
    printf("%d\n", start_o);
    printf("%d\n", end);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        array[i] = temp;
    }

    int ret = maxSum(0, n - 1);
    findIndex();
    printf("%d\n", ret);
    return 0;
}