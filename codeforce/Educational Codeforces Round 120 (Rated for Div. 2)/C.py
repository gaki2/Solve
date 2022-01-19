import math
from collections import deque
t = int(input())
ret = [];
for _ in range(t):
    n, k = map(int,input().split());
    arr = list(map(int,input().split()));
    ans = 1e16;
    arr.sort();
    a1 = arr[0];
    p = [0] * (n+1);

    for i in range(n):
        p[i+1] = p[i] + arr[i];

    for i in range(n):
        x = math.ceil(a1 - ((k + a1 - p[n-i]) / (i+1)));
        if x < 0 :
            x = 0;
        ans = min(ans, x + i);
    
    ret.append(ans);

for a in ret:
    print(a);
        
            


        
    
