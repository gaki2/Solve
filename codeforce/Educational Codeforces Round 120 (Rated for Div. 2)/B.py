t = int(input())

for _ in range(t):
    n = int(input())
    rating = list(map(int, input().split(' ')))
    likes = list(input())
    likes = list(map(int, likes))

    dislike = []
    like = []

    for i, v in enumerate(rating):
        if likes[i] == 0:
            dislike.append(v)
        else:
            like.append(v)
    dislike.sort()
    like.sort()
    ret = {}

    iter = 0
    for i in range(n+1 - len(like), n+1):
        ret[like[iter]] = i
        iter += 1
    iter = 0
    for i in range(1, len(dislike) + 1):
        ret[dislike[iter]] = i
        iter += 1
    for rate in rating:
        print(ret[rate], end=' ')
