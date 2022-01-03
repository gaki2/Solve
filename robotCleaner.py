n = int(input())


def canClean(rn, cn, rd, cd):
    if (rn == rd or cn == cd):
        return True
    else:
        return False


li = []
for _ in range(n):
    n, m, rn, cn, rd, cd = map(int, input().split())
    dx = 1
    dy = 1
    t = 0
    while(not canClean(rn, cn, rd, cd)):
        if (rn + dy > n or rn + dy < 1):
            dy *= -1
        if (cn + dx > m or cn + dx < 1):
            dx *= -1
        rn = rn + dy
        cn = cn + dx
        t += 1
    li.append(t)
for i in li:
    print(i)
