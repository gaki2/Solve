import math;

roots = [0] * 11;

for i in range(1,11):
    roots[i] = i;


#최상단 부모 루트노드를 찾는 함수
def find(nodeNumber):
    if (roots[nodeNumber] == nodeNumber):
        return nodeNumber;
    else:
        return find(roots[nodeNumber]);


def union(willParentNode, willChildNode):
    x = find(willParentNode);
    y = find(willChildNode);
    
    roots[y] = x;

union(1,3);
union(1,5);
union(3,7);

print(find(7)) # 1 이 나와야됨. 