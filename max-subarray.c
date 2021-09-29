#include <stdio.h>
#define INF -1234567890
#define max(a, b) (((a) > (b)) ? (a) : (b))
int array[10000];

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

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        array[i] = temp;
    }

    int ret = maxSum(0, n - 1);
    printf("%d\n", ret);
    return 0;
}