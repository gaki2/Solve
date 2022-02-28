import heapq;

V,e = map(int, input().split());
start = int(input());
infos = list([] for _ in range(V + 1));
heap = [];
for i in range(e):
    u,v,w = map(int, input().split());
    infos[u].append([w,v]);
INF = 1e9;
D = [INF] * (V + 1);
D[start] = 0;

def diakstra(start, heap, D, infos):
    heapq.heappush(heap, [0, start]);
    while (heap):
        distance, middle = heapq.heappop(heap);
        for w,v in infos[middle]:
            if (D[v] > distance + w):
                D[v] = distance + w;
                heapq.heappush(heap, [distance + w, v]);

diakstra(start, heap, D, infos);

for i in range(1, V + 1):
    if (D[i] == INF):
        print("INF");
    else:
        print(D[i]);