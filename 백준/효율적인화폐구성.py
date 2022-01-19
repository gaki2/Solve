import math
dp = [math.inf] * 10001
n, m = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

coins.sort()

for coin in coins:
    dp[coin] = 1


for i in range(max(coins)+1, m+1):
    for j in coins:
        dp[i] = min(dp[i-j] + 1, dp[i])

if (dp[m] == math.inf):
    print(-1)
else:
    print(dp[m])
