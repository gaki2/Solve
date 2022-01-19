N = int(input())
move = list(input().split())
print(move)
x = 1
y = 1

for m in move:
    temp_x = x
    temp_y = y
    if (m == 'R'):
        x += 1
    elif (m == 'L'):
        x -= 1
    elif (m == 'U'):
        y -= 1
    else:
        y += 1

    if ((x < 1 or x > N) or (y < 1 or y > N)):
        x = temp_x
        y = temp_y

print(y, x)
