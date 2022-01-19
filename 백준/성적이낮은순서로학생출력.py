n = int(input())
arr = []

for _ in range(n):
    name, grade = input().split()
    arr.append((name, int(grade)))


def setting(tuple):
    return tuple[1]


arr.sort(key=setting)

for tuple in arr:
    print(tuple[0], end=' ')
