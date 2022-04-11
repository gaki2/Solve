# 32분

import math;

def solution(s):
    answer = 0
    
    if (len(s) == 3 and s[0] == s[1] == s[2]):
        return 2;
    if (len(s) <= 3):
        return len(s);
    
    beforeString = "";
    
    # 4일떄?
    for i in range(1, math.floor(len(s) / 2) + 1):
        newString = "";
        scale = i;
        partedArr = [s[j:j+scale] for j in range(0, len(s), scale)];
        temp = "";
        mul = 1;
        for k in range(0,len(partedArr)):
            if (k != len(partedArr) - 1):
                if (partedArr[k] == partedArr[k+1]):
                    mul += 1;
                    temp = str(mul) + partedArr[k];
                else:
                    mul = 1;
                    if (temp):
                        newString += temp;
                        temp = "";
                    else :
                        newString += partedArr[k];
            if (k == len(partedArr) - 1):
                    if (temp):
                        newString += temp;
                        temp = "";
                    else:
                        newString += partedArr[k];
        if (len(beforeString) == 0):
            beforeString = newString;
        if (len(beforeString) > len(newString)):
            beforeString = newString;
            
    print(beforeString);
        
    return len(beforeString);