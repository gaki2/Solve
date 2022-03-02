point = input()
trans = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
dx = [2, 2, -2, -2, 1, -1, 1, -1]
dy = [1, -1, 1, -1, 2, 2, -2, -2]
cnt = 0

for i in range(8):
    if trans[i] == point[0]:
        x = i + 1
        break
y = int(point[1])
print(x, y)

for i in range(8):
    ddx = x + dx[i]
    ddy = y + dy[i]
    if (ddx < 1 or ddx > 8 or ddy < 1 or ddy > 8):
        continue
    else:
        cnt += 1

print(cnt)
