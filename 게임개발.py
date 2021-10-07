from copy import deepcopy
n, m = map(int, input().split())
x, y, dir = map(int, input().split())
graph = []
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

for _ in range(n):
    graph.append(list(map(int, input().split())))

visited = deepcopy(graph)

# print(graph)


def changeDir():
    global dir
    dir -= 1
    if (dir == -1):
        dir = 3


cnt = 1
visited[y][x] = 1


def solve(x, y):
    global cnt
    if (check4way(x, y) == False):
        changeDir()
        changeDir()
        ddx = x + dx[dir]
        ddy = y + dy[dir]
        changeDir()
        changeDir()
        if (graph[ddy][ddx] == 1 or ddx < 0 or ddx >= m or ddy < 0 or ddy >= n):
            return
        else:
            solve(ddx, ddy)
    changeDir()
    ddx = x + dx[dir]
    ddy = y + dy[dir]
    if (graph[ddy][ddx] == 0 and visited[ddy][ddx] == 0):
        x = ddx
        y = ddy
        cnt += 1
        visited[y][x] = 1
        solve(x, y)
    else:
        solve(x, y)


def check4way(x, y):
    cnt = 0
    for i in range(4):
        ddx = x + dx[i]
        ddy = y + dy[i]
        if (ddx < 0 or ddx >= m or ddy < 0 or ddy >= n):
            cnt += 1
            continue
        if (graph[ddy][ddx] == 1 or visited[ddy][ddx]):
            cnt += 1
            continue
    if cnt == 4:
        return False
    else:
        return True


solve(x, y)
print(cnt)
