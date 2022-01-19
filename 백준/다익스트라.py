import copy

class MinHeap:
    def __init__(self):
        self.queue = [None]

    def parent(self, index):
        return int(index/2)

    def insert(self, pair):
        self.queue.append(pair)
        i = len(self.queue) - 1
        while i > 1:
            parent = self.parent(i)
            if self.queue[i][1] < self.queue[parent][1]:
                self.swap(i, parent)
                i = parent
            else:
                break

    def swap(self, a, b):
        temp1 = self.queue[a][0];
        temp2 = self.queue[a][1];
        self.queue[a][0], self.queue[a][1] = self.queue[b][0], self.queue[b][1];
        self.queue[b][0], self.queue[b][1] = temp1, temp2;

    def delete(self):
        self.swap(1, len(self.queue)-1)
        ret = self.queue.pop(len(self.queue)-1)
        self.minHeapify(1)
        return ret

    def rightChild(self, index):
        return index * 2

    def leftChild(self, index):
        return (index * 2) + 1

    def minHeapify(self, i):
        left = self.leftChild(i)
        right = self.rightChild(i)
        small = i
        if left <= len(self.queue)-1 and self.queue[left][1] < self.queue[small][1]:
            small = left
        if right <= len(self.queue)-1 and self.queue[right][1] < self.queue[small][1]:
            small = right
        if small != i:
            self.swap(i, small)
            self.minHeapify(small)

heap = MinHeap();

nodes = sorted(input().split(','));
nodes_len = len(nodes);
n = int(input());


def makeGraph(n):
    INF = 10000000000;
    graph = [];
    for _ in range(nodes_len):
        graph.append([INF] * nodes_len);
    
    for i in range(nodes_len):
        graph[i][i] = 0;

    for j in range(n):
        data = input().split(',');
        graph[nodes.index(data[0])][nodes.index(data[1])] = int(data[2]);

    return graph;

graph = makeGraph(n);

def dijkstra():
    v = [0] * nodes_len;
    d = copy.deepcopy(graph[nodes.index('A')]);
    
    for idx, value in enumerate(d):
        heap.insert([idx, value]);
    v[nodes.index('A')] = 1; #A방문체크
    while(len(heap.queue) > 1) :
        newElem = heap.delete();
        node = newElem[0];
        if (v[node] == 1) :
            continue;
        v[node] = 1;
        dis = newElem[1];
        for i in range(len(d)):
            newd = graph[node][i] + dis;
            if (newd < graph[0][i]):
                graph[0][i] = newd;
                d[i] = newd;
                heap.insert([i, newd]);
    return d;

ret = dijkstra();
for i in ret:
    print(i);




