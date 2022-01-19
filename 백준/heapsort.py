def sort(list, idx, n):
    left_child = idx * 2
    right_child = idx * 2 + 1
    start_idx = idx
    if (left_child <= n and list[start_idx] > list[left_child]):
        start_idx = left_child
    if (right_child <= n and list[start_idx] > list[right_child]):
        start_idx = right_child
    if start_idx != idx:
        list[idx], list[start_idx] = list[start_idx], list[idx]
        return sort(list, start_idx, n)


def heap_sort(list):
    n = len(list)
    list = [0] + list

    for i in range(n, 0, -1):
        sort(list, i, n)

    for j in range(n, 0, -1):
        print(list[1])
        list[j], list[1] = list[1], list[j]
        sort(list, 1, j-1)


n = int(input())

list = []
for _ in range(n):
    temp = int(input())
    list.append(temp)

heap_sort(list)
