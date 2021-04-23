#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    //step 1 : upper -> lower
    for (int i = 0; i < new_id.size(); i++)
    {
        if ('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] += 32;
    }
	cout << "step 1 clear" << '\n';
    //step 2 : remove 
    string exception = "~!@#$%^&*()=+[{]}:?,<>/";
    for (string::iterator iter = new_id.begin(); iter < new_id.end();)
    {
        for (int j = 0; j < exception.size(); j++)
        {
            if (*iter == exception[j]){
                new_id.erase(iter);
                break ;
            }
            if (j == exception.size() - 1)
                iter++;
        }
    }

	cout << "step 2 clear" << '\n';
    
    //step 3 : .
	string::iterator iter = new_id.begin();
    for (int i = 0; i < new_id.size() - 1;){
        if (new_id[i] == '.' && new_id[i+1] == '.')
        {
            new_id.erase(iter + i);
        }
        else
        {
            i++;
        }
    }
    
	cout << "step 3 clear" << '\n';
    
	//step 4 : .
    if (new_id[0] == '.')
    {
        new_id.erase(new_id.begin());
    }
    if (new_id[new_id.size() - 1] == '.')
    {
        new_id.erase(new_id.end() - 1);
    }
    
    //step 5 : is blank?
    if (new_id.size() == 0)
    {
        new_id = "a";
    }

	cout << "step 4,5 clear" << '\n';

    //step 6 : size is longer than 16?
	if (new_id.size() >= 16)
	{
		new_id.erase(15, new_id.size());
	}

	if (*(new_id.end() - 1) == '.')
		new_id.erase(new_id.end() - 1);

    //step 7 : size is shorter than 2?
    if (new_id.size() <= 2)
    {
        char a = new_id[new_id.size() - 1];
        while (new_id.size() < 3)
        {
            new_id += a;
        }
    }

    return new_id;
}


int main(void)
{
	string a;
	cin >> a;
	cout << solution(a) << '\n';
}
