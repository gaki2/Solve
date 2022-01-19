from copy import deepcopy

graph = []
cnt = 0


def count(mono, node, visited):
    global cnt
    visited[node] = 1
    cnt += 1
    ret = 0
    for i in mono[node]:
        if visited[i]:
            continue
        else:
            count(mono, i, visited)
    return


def solution(n, wires):
    ret = 1000000000
    global cnt

    for i in range(n + 1):
        graph.append([])

    for v, w in wires:
        graph[v].append(w)
        graph[w].append(v)

    for v, w in wires:
        mono = [item[:] for item in graph]

        mono[v].remove(w)
        mono[w].remove(v)
        visited = [0]*(n + 1)
        cnt = 0
        count(mono, v, 1, visited)
        a = cnt
        visited = [0]*(n + 1)
        cnt = 0
        count(mono, w, 1, visited)
        b = cnt
        print("a", a, "b", b)
        ret = min(ret, abs(a-b))

    return ret
