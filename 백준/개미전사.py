dp = [-1] * 101
n = int(input())
a = list(map(int, input().split()))


def init(dp, a):
    dp[1] = a[0]
    dp[2] = max(a[0], a[1])


init(dp, a)

for i in range(3, n + 1):
    dp[i] = max(dp[i-1], dp[i-2] + a[i-1])

ret = max(dp[n], dp[n-1])

print(ret)
