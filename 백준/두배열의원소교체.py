n, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()
a_idx = 0
b_idx = n-1

while(k != 0):
    if (a_idx >= n or b_idx < 0):
        break
    if (a[a_idx] < b[b_idx]):
        a[a_idx], b[b_idx] = b[b_idx], a[a_idx]
        a_idx += 1
        b_idx -= 1
        k -= 1
    else:
        break

print(sum(a))
