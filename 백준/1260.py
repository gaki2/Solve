from collections import deque
n,m,s = map(int, input().split());

graph = [];

for _ in range(n + 1):
    graph.append([]);

for _ in range(m):
    a,b = map(int, input().split());
    graph[a].append(b);
    graph[a].sort();
    graph[b].append(a);
    graph[b].sort();


visited = [0] * (n + 1);
def dfs(startIdx):
    visited[startIdx] = 1;
    print(startIdx, end=' ');

    for i in graph[startIdx]:
        if (visited[i] == 0) :
            dfs(i)

dfs(s);

visited = [0] * (n + 1);
print('');
def bfs(startIdx):
    queue = deque([]);
    queue.append(startIdx);
    visited[startIdx] = 1;

    while(queue):
        now = queue.popleft();
        print(now, end=' ');
        for i in graph[now]:
            if (not visited[i]):
                queue.append(i);
                visited[i] = 1;
    
bfs(s);




    

