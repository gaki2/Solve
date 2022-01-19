#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for(int i = 0; i < new_id.size(); i++) {
        if(('A' <= new_id[i]) && (new_id[i] <= 'Z')) {
            tolower(new_id[i]);
        }
    }

    for(int j = 0; j < new_id.size())


    return answer;
}