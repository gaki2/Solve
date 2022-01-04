import copy
from collections import deque
t = int(input())

cnt = 0
ret = 0
for _ in range(t):
    n, k = map(int, input().split())
    array = list(map(int, input().split()))
    queue = deque()
    queue.append((cnt, array))
    while(queue):
        nowItem = queue.popleft()
        nowCnt, nowArr = nowItem
        if (sum(nowArr) <= k):
            ret = nowCnt
            break
        nowArr.sort()
        for i in range(2):
            if (i == 0):  # set
                newArr = copy.deepcopy(nowArr)
                newArr[-1] = newArr[0]
                queue.append((nowCnt + 1, newArr))
            if (i == 1):  # decrease
                newArr2 = copy.deepcopy(nowArr)
                newArr2[0] -= 1
                queue.append((nowCnt + 1, newArr2))
    print(ret)
