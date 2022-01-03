t = int(input())

for _ in range(t):
    length = list(map(int, input().split()))
    length.sort()
    a, b, c = length
    if (a+b == c or (a == b and c % 2 == 0) or (b == c and a % 2 == 0)):
        print("YES")
    else:
        print("NO")
