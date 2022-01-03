t = int(input())


for _ in range(t):
    n, m = map(int, input().split())
    expectPointX = list(map(int, input().split()))
    grades = []
    for _ in range(n):
        grade = input()
        grades.append(grade)
