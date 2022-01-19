

def solution(n, costs):
    costs.sort(key=lambda x: x[2]);
    count = n - 1;
    answer = 0;
    roots = [0] * n;
    for i in range(n):
        roots[i] = i;
    
    
    def find(node, roots):
        if (node == roots[node]):
            return node;
        else:
            return find(roots[node], roots);
    
    def union(parentNode, childNode, roots):
        x = find(parentNode, roots);
        y = find(childNode, roots);
        
        roots[y] = x;
    
    for cost in costs:
        node1 = cost[0];
        node2 = cost[1];
        value = cost[2];
        
        if (find(node1, roots) == find(node2, roots)):
            continue;
        else:
            answer += value;
            union(node1, node2, roots);
            count -= 1;
        
        if (count == 0):
            break
    return answer;