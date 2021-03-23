#include <stdio.h>
#include <math.h>

int		main(void)
{
		int		start;
		int		finish;
		int		floor;
		int		case_arr[5000] = { 0,};
		int		n;
		int		cnt;
		int		test;
		

		case_arr[1] = 1;
		floor = 1;
		while(floor < 11)
		{
				start = pow(2, floor - 1);
				finish = (pow(2, floor) - 1);
				while (start <= finish)
				{
						if (case_arr[start] == 1)
						{
								case_arr[start * 2] = 1;
								case_arr[start * 2 + 1] = 2;
						}
						else if (case_arr[start] == 2)
						{
								case_arr[start * 2] = 1;
								case_arr[start * 2 + 1] = 3;
						}
						else if (case_arr[start] == 3)
								case_arr[start * 2] = 1;
						start++;
				}
				floor++;
		}
		scanf("%d", &test);
		while (test)
		{
			scanf("%d", &n);
			cnt = 0;
			start = pow(2, n - 1);
			finish = pow(2, n) - 1;
			while (start <= finish)
			{
				if (case_arr[start] != 0)
						cnt++;
				start++;
			}
			printf("%d",cnt);
			test--;
		}
		return (0);
}


	
