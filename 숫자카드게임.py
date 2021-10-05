n, m = map(int, input().split())

min_arr = []
for _ in range(n):
    arr = list(map(int, input().split()))
    min_arr.append(min(arr))

print(max(min_arr))
