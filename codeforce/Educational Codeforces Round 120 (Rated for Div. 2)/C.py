t = int(input())
ret = []

for _ in range(t):
    n, k = map(int, input().split())
    sequence = list(map(int, input().split(' ')))
    sequence.sort()
    cnt = 0

    while(sequence[0] * n > k):
        cnt += 1
        sequence[0] = sequence[0] - 1

    ret.append(cnt)

for r in ret:
    print(r)
