import sys

n = int(input())
myItem = list(map(int, input().split()))
myItem.sort()
m = int(input())
requests = list(map(int, input().split()))


def biSearch(lo, hi, num):
    if (lo > hi):
        return False
    mid = (lo + hi) // 2
    if (myItem[mid] == num):
        return True
    if (myItem[mid] < num):
        return biSearch(mid+1, hi, num)
    elif (myItem[mid] > num):
        return biSearch(lo, mid - 1, num)


for num in requests:
    ret = biSearch(0, n-1, num)
    if (ret):
        print('yes', end=' ')
    else:
        print('no', end=' ')
