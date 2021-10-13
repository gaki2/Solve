n = int(input())

dp = [-1] * 30001


def init(dp):
    dp[1] = 0
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2


init(dp)


for i in range(5, n + 1):
    list = []

    if (i % 5 == 0):
        cnt1 = dp[i//5] + 1
        list.append(cnt1)
    if (i % 3 == 0):
        cnt2 = dp[i//3] + 1
        list.append(cnt2)
    if (i % 2 == 0):
        cnt3 = dp[i//2] + 1
        list.append(cnt3)
    cnt4 = dp[i-1] + 1
    list.append(cnt4)

    dp[i] = min(list)

print(dp[n])
