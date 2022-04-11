#https://programmers.co.kr/learn/courses/30/lessons/72410?language=python3
# 걸린시간 22분 
# 
def step2(string):
    newString = "";
    for i in range(len(string)):
        nowChar = string[i];
        if (nowChar.islower() or  '0' <= nowChar <= '9' or nowChar == "-" or nowChar == "_" or nowChar == ".") :
            newString += nowChar;
    return newString;
    

def solution(new_id):
    answer = ''
    
    answer = new_id.lower();
    answer = step2(answer);
    while (answer.find("..", 0) != -1):
        answer = answer.replace("..", ".");
    
    while (answer != "" and answer[0] == "."):
        answer = answer[1:];
    while (answer != "" and answer[-1] == "."):
        answer = answer[: -1];
    
    if (answer == ""):
        answer += "a";
    
    if (len(answer) >= 16):
        answer = answer[0:15];
    
    while (answer[0] == "."):
        answer = answer[1:];
    while(answer[-1] == "."):
        answer = answer[: -1];
    
    while (len(answer) <= 2):
        answer += answer[-1];
    
    
    return answer