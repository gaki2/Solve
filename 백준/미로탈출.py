from copy import deepcopy
from collections import deque
n, m = map(int, input().split())
graph = []
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(n):
    graph.append(list(map(int, input())))

visited = []

for _ in range(n):
    visited.append([0]*m)


def bfs():
    queue = deque()
    queue.append({'x': 0, 'y': 0, 'cnt': 1})
    visited[0][0] = 1
    while queue:
        now = queue.popleft()
        cnt = now['cnt']
        if (now['x'] == m - 1 and now['y'] == n - 1):
            return cnt
        for i in range(4):
            ddx = now['x'] + dx[i]
            ddy = now['y'] + dy[i]
            if (ddx < 0 or ddx > m - 1 or ddy < 0 or ddy > n - 1 or graph[ddy][ddx] == 0 or visited[ddy][ddx] == 1):
                continue
            visited[ddy][ddx] = 1
            queue.append({'x': ddx, 'y': ddy, 'cnt': cnt + 1})


print(bfs())
