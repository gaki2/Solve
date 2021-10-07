n, m = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(input()))
cnt = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(x, y):
    global graph
    graph[y][x] = '1'
    for i in range(4):
        ddx = x + dx[i]
        ddy = y + dy[i]
        if (ddx < 0 or ddx >= m or ddy < 0 or ddy >= n or graph[ddy][ddx] == '1'):
            continue
        dfs(ddx, ddy)


for y in range(n):
    for x in range(m):
        if (graph[y][x] == '0'):
            cnt += 1
            dfs(x, y)

print(cnt)
