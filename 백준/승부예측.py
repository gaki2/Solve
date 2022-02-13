from collections import defaultdict;

teams = list(input().split());
chances = [];
ans = defaultdict(list);

for team in teams:
    ans[team] = 0;

for i in range(6):
    temp = list(input().split());
    chances.append(temp);

def calChance(chance, ans):
    mm = 1.00000000;
    d = defaultdict(int);

    for c in chance:
        teamA = c[0];
        scoreA = int(c[1]);
        teamB = c[2];
        scoreB = int(c[3]);
        m = float(c[4]);
        mm *= m;
        d[teamA] += scoreA;
        d[teamB] += scoreB;
    d = dict(sorted(d.items(), key=lambda item : -item[1]));
    
    temp = [];
    for key in d.keys():
        temp.append([key, d[key]]);
    
    # 2 등이 3등보다 승점이 높은경우
    if (temp[1][1] > temp[2][1]):
        ans[temp[0][0]] += mm;
        ans[temp[1][0]] += mm;
    
    # 2 등이 3등과 점수가 같을 경우
    else:
        # 3,4 등도 2등과 점수가 같은경우
        if (temp[2][1] == temp[3][1]):
            # 1,2 등도 점수가 같은경우
            if (temp[0][1] == temp[1][1]):
                for t in temp:
                    ans[t[0]] += (mm/2);
            # 1등과 2등이 점수가 같지 않은경우
            elif (temp[0][1] != temp[1][1]):
                ans[temp[0][0]] += mm;
                ans[temp[1][0]] += mm/3;
                ans[temp[2][0]] += mm/3;
                ans[temp[3][0]] += mm/3;
        # 3등과 4등이 점수가 같지 않은 경우
        elif (temp[2][1] != temp[3][1]):
            # 1 등과 2 등이 점수가 같은 경우
            if (temp[0][1] == temp[1][1]):
                ans[temp[0][0]] += (mm*2)/3;
                ans[temp[1][0]] += (mm*2)/3;
                ans[temp[2][0]] += (mm*2)/3;
           # 1등과 2등이 점수가 같지 않은경우
            elif (temp[0][1] != temp[1][1]):
                ans[temp[0][0]] += mm;
                ans[temp[1][0]] += mm/2;
                ans[temp[2][0]] += mm/2;

def dfs(level, idx, chance, ans):
    global chances;
    nowTeams = chances[level - 1];
    if idx == 0:
        temp = [nowTeams[0], 3,nowTeams[1], 0, nowTeams[idx + 2]];
    elif idx == 1:
        temp = [nowTeams[0], 1,nowTeams[1], 1, nowTeams[idx + 2]];
    elif idx == 2:
        temp = [nowTeams[0], 0,nowTeams[1], 3, nowTeams[idx + 2]];
    chance.append(temp);
    
    if (level == 6):
        calChance(chance, ans);
        chance.pop();
        return ;
    
    for i in range(3):
        if float(chances[level][i+2]) != 0:
            dfs(level + 1, i, chance, ans);
    chance.pop();


for i in range(3):
    if float(chances[0][i + 2]) != 0:
        dfs(1, i, [], ans);

for t in teams:
    print(ans[t]);

