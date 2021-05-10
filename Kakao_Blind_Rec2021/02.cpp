#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> db[3][2][2][2];
	vector<int> answer;
    
	for (int i = 0; i < info.size(); i++)
	{
		vector<int> IDX;
		string temp;
		stringstream stream;
		stream.str(info[i]);
		while (stream >> temp)
		{
			if (temp == "cpp" || temp == "backend" || temp == "junior" || temp == "chicken")
			{
				IDX.push_back(0);
			}
			else if (temp == "java" || temp == "frontend" || temp == "senior" || temp == "pizza")
			{
				IDX.push_back(1);
			}
			else if (temp == "python")
				IDX.push_back(2);
			else
			{
				int grade;
				grade = stoi(temp);
				IDX.push_back(grade);
			}
		}
		db[IDX[0]][IDX[1]][IDX[2]][IDX[3]].push_back[IDX[4]];
	}
	// quick sort;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			for (int z = 0; z < 2; z++)
				for (int k = 0; k < 2; k++)
					sort(db[i][j][z][k].begin(), db[i][j][z][k].end());

	for (int q = 0; q < query.size(); q++)
	{
		stringstream stream;
		stream.str(query[q]);
		string temp;
		int IDX_RANGE[4][2];
		int now1, now2;
		int pointer;
        int grade;
        pointer = 0;
		vector <string> value;
		while (stream >> temp)
		{
			if (temp == "and")
				continue ;
			value.push_back(temp);
		}
		for (int s = 0; s < 4; s++)
		{
			if (value[s] == "cpp") now1=now2=0;
			else if (value[s] == "java")  now1=now2=1;
			else if (value[s] == "python") now1=now2=2;
			else if (value[s] == "-") { now1=0; now2=2;}

			if (value[s] == "backend") now1=now2=0;
			else if(value[s] == "frontend") now1=now2=1;
			else if (value[s] == "-") { now1 = 0; now2 = 1;}

			if (value[s] == "junior") now1=now2=0;
			else if (value[s] == "senior") now1=now2=1;
			else if (value[s] == "-") {now1 = 0; now2= 1;}

			if (value[s] == "chicken") now1=now2=0;
			else if (value[s] == "pizza") now1=now2=1;
			else if (value[s] == "-") {now1 =0; now2= 1;}

			IDX_RANGE[s][0] = now1;
			IDX_RANGE[s][1] = now2;
		}
		grade = stoi(value[4]);
		
		int ret = 0;
		for (int i = IDX_RANGE[0][0]; i <= IDX_RANGE[0][1]; i++)
			for (int j = IDX_RANGE[1][0]; j <= IDX_RANGE[1][1]; j++)
				for (int z = IDX_RANGE[2][0]; z <= IDX_RANGE[2][1]; z++)
					for (int k = IDX_RANGE[3][0]; k <= IDX_RANGE[3][1]; k++)
					{
						int diff = db[i][j][z][k].end() - lower_bound(db[i][j][z][k].begin(), db[i][j][z][k].end(), grade);
						ret += diff;
					}
        answer.push_back(ret);
    }
	return answer;
}