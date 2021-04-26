#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int diff;


typedef struct _Truck
{
	int distance, capa_weight;
	struct _Truck *next;
} Truck;

void go_straight(Truck *t)
{
	t->distance += 1;
	Truck *next_t = t->next;
	while(next_t != NULL)
	{
		next_t->distance+= 1;
		next_t = next_t->next;
	}
}

bool is_arrive(Truck *head, int bridge_lenth)
{
	if (head->distance == bridge_lenth)
	{
		return (true);
	}
	return (false);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
	int answer = 0;
	int Truck_Num = truck_weights.size();


	Truck *new_truck = NULL;
	Truck *head = NULL;
	Truck *tail = NULL;

	while (1)
	{
		if (!truck_weights.empty())
		{
			if (head == NULL)
			{
				new_truck = new Truck;
			new_truck->distance = 0;
			new_truck->capa_weight = weight - truck_weights.front();
			truck_weights.erase(truck_weights.begin());
			new_truck->next = NULL;
			head = new_truck;
			tail = new_truck;
		}

		else
		{
			if ((tail->capa_weight) - truck_weights.front() >= 0)
			{
				new_truck = new Truck;
				new_truck->distance = 0;
				new_truck->capa_weight = tail->capa_weight - truck_weights.front();
				truck_weights.erase(truck_weights.begin());
				new_truck->next = NULL;
				tail->next = new_truck;
				tail = new_truck;
			}
		}
		}
		go_straight(head);
		answer++;
		if (is_arrive(head, bridge_length))
		{
			Truck_Num--;
			Truck *delete_head = head;
			diff = weight - head->capa_weight;
			head = head->next;
			if (head == NULL)
			{
				tail = NULL;
			}
			else
			{
				tail->capa_weight += diff;
			}
			delete delete_head;
		}
		if (Truck_Num == 0)
			return (answer);
	}
}

int main(void)
{
	int a = 100;
	int w = 100;
	vector<int> c;
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	c.push_back(10);
	cout << solution(a,w,c) + 1 << endl;
}




	










