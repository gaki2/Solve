# 18분
# default dict, set 에서 엘리먼트 하는 메서드는 add, set 에서 엘리먼트에 인덱스로 접근 불가능
# => for a in set 으로 요소에 직접 접근해야함.


from collections import defaultdict;

def solution(id_list, report, k):
    answer = [];
    
    reportSet = defaultdict(set);
    mail = defaultdict(int);
    
    for i in range(len(id_list)):
        nowUser = id_list[i];
        reportSet[nowUser];
        mail[nowUser];
    
    for i in range(len(report)):
        [user, reportedUser] = report[i].split();
        
        reportSet[reportedUser].add(user);
    
    for key in reportSet:
        if (len(reportSet[key]) >= k):
            for user in reportSet[key]:
                mail[user] += 1;
    
    for key in mail:
        answer.append(mail[key]);
    
        
    
    return answer;