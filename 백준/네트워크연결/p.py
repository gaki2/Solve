n = int(input());
count = n - 1;
answer = 0;
roots = [0] * (n + 1);

for i in range(n + 1):
    roots[i] = i;

m = int(input());

costs = [];

for _ in range(m):
    a = list(map(int,input().split()));
    costs.append(a);

costs.sort(key=lambda x:x[2]);

def find(node):
    if (roots[node] == node):
        return node;
    else:
        return find(roots[node]);

def union(node1, node2):
    x = find(node1);
    y = find(node2);
    roots[x] = y;

for cost in costs:
    firstNode = cost[0];
    secondNode = cost[1];
    value = cost[2];
    if (find(firstNode) == find(secondNode)):
        continue;
    else:
        count -= 1;
        answer += value;
        union(firstNode, secondNode);
    if (count == 0):
        break;

print(answer);


