#include <string>
#include <vector>
#include <cmath>
using namespace std;

string toSecond(long long number)
{
    string ret = "";
    while (number != 0)
    {
        long long rest = number % 2;
        number /= 2;
        ret.insert(0, to_string(rest));
    }

    return ret;
}

long long toDecimal(string second)
{
    int len = second.size() - 1;
    int i = 0;
    long long ret = 0;
    while (len != -1)
    {
        int temp = (second[i] - '0');
        ret += temp * pow(2, len);
        len--;
        i++;
    }
    return ret;
}

string transform(string s)
{
    s.insert(0, "0");
    int len = s.size();
    int breakpoint;

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            breakpoint = i;
            break;
        }
    }
    if (breakpoint != len - 1)
    {
        s[breakpoint + 1] = '0';
    }

    return s;
}

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long ret = toDecimal(transform(toSecond(numbers[i])));
        answer.push_back(ret);
    }
    return answer;
}