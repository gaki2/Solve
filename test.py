import time

arr = []

for j in range(10000):
    arr.append(j)

arr2 = []

for i in range(10000):
    arr2.append(arr)

start = time.time()  # 시작 시간 저장
cnt = 0
for i in range(10000):
    for j in range(10000):
        cnt += arr2[j][i]

print(cnt)

print("time :", time.time() - start)  # 현재시각 - 시작시간 = 실행 시간
