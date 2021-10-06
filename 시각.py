n = int(input())

noThree = 15 * 45 * 2 + 15 * 15
withThree = 3600
cnt = 0
for k in range(n + 1):
    if (k == 3 or k == 13 or k == 23):
        cnt += withThree
    else:
        cnt += noThree

print(cnt)
