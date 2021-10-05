n, m, k = map(int, input().split())


arr = list(map(int, input().split()))
arr.sort()
div, mod = divmod(m, (k + 1))
print(div, mod)
ret = (arr[n-1] * k + arr[n-2]) * div + (arr[n-1] * mod)

print(ret)
