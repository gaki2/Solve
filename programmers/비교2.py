

def solution(n, costs):
    numOfLine = n - 1;
    roots = [0] * n;
    
    for i in range(n):
        roots[i] = i;
    
    def find(node):
        if (node == roots[node]):
            return int(node);
        else:
            find(roots[node]);
    
    def union(node1, node2):
        x = find(node1);
        y = find(node2);
        print(x,y)
        # print(roots[x,y);
        roots[x] = y;
    
    answer = 0
    costs.sort(key=lambda x:x[2]);
    
    
    for cost in costs:
        node1 = int(cost[0]);
        node2 = int(cost[1]);
        if (find(node1) == find(node2)):
            continue;
        else:
            union(node1, node2);
            answer += cost[2];
            numOfLine -= 1;
        if (numOfLine == 0):
            break;
            
    return answer;