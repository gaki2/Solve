#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> db[3][2][2][2];

void fillDB(vector<string>info) {
    for(int i = 0; i < info.size(); i++) {
        // 1개의 정보 : info[i]
        // temp
        string temp = "";
        int a = 0,b =0,cc = 0,d = 0;
        for(char c : info[i]) {
            if (c == ' ') {
                if (temp == "cpp") {
                    a = 0;
                } else if (temp == "java") {
                    a = 1;
                } else if (temp == "python") {
                    a = 2;
                } else if (temp == "backend") {
                    b = 0;
                } else if (temp == "frontend") {
                    b = 1;
                } else if (temp == "junior") {
                    cc = 0;
                } else if (temp == "senior") {
                    cc = 1;
                } else if (temp == "chicken") {
                    d = 0;
                } else if (temp == "pizza") {
                    d = 1;
                }
                temp = "";
            } else {
                temp += c;
            }
        }
        db[a][b][cc][d].push_back(stoi(temp));
    }
}

vector<string> parseQuery(string query) {
    vector<string> s;

    string temp = "";
    for(char c : query) {
        if (c == ' ') {
            if (temp != "" && temp != "and") {
                s.push_back(temp);
            }
            temp = "";
        } else {
            temp += c;
        }
    }
    s.push_back(temp);
    return s;
}

void sort(void) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    sort(db[i][j][k][m].begin(), db[i][j][k][m].end());
                }
            }
        }
    }
}

vector<int> startQuery(vector<string> query) {
    vector<int> answer;
    sort();
    for(int i = 0; i < query.size(); i++) {
        // query[i] : 쿼리 명령 한개
        int a1 = 0;
        int a2 = 0;
        int b1 = 0;
        int b2 = 0;
        int c1 = 0;
        int c2 = 0;
        int d1 = 0;
        int d2 = 0; 
        vector<string> queryData = parseQuery(query[i]);
        // [0] [1] [2] [3] [4]
        if (queryData[0] == "cpp") {
            a1 = a2 = 0;
        } else if (queryData[0] == "java") {
            a1 = a2 = 1;
        } else if (queryData[0] == "python") {
            a1 = a2 = 2;
        } else if (queryData[0] == "-") {
            a1 = 0;
            a2 = 2;
        }
        
        if (queryData[1] == "backend") {
            b1 = b2 = 0;
        } else if (queryData[1] == "frontend") {
            b1 = b2 = 1;
        } else if (queryData[1] == "-") {
            b1 = 0;
            b2 = 1;
        }

        if (queryData[2] == "junior") {
            c1 = c2 = 0;
        } else if (queryData[2] == "senior") {
            c1 = c2 = 1;
        } else if (queryData[2] == "-") {
            c1 = 0;
            c2 = 1;
        }

        if (queryData[3] == "chicken") {
            d1 = d2 = 0;
        } else if (queryData[3] == "pizza") {
            d1 = d2 = 1;
        } else if (queryData[3] == "-") {
            d1 = 0;
            d2 = 1;
        }

        int ans = 0;
        

        for(int a = a1; a <= a2; a++) {
            for(int b = b1; b <= b2; b++) {
                for (int c = c1; c <= c2; c++) {
                    for (int d = d1; d <= d2; d++) {
                        if (db[a][b][c][d].size() == 0) {
                            continue;
                        }
                        // 오름차순으로 정렬 후 이진탐색
                        auto iter = lower_bound(db[a][b][c][d].begin(), db[a][b][c][d].end(), stoi(queryData[4]));
                        int preItemsNum = iter - db[a][b][c][d].begin();
                        int ret = db[a][b][c][d].size() - preItemsNum;
                        ans += ret;
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}


vector<int> solution(vector<string> info, vector<string> query) {
    fillDB(info);
    return startQuery(query);
}