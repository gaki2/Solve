n, k = map(int, input().split())
cnt = 0
while(n > 1):
    if (n % k == 0):
        n = n//k
        cnt += 1
    else:
        diff = (n % k)
        n -= diff
        cnt += diff

print(cnt)
