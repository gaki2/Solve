#include <iostream>
#include <vector>
using namespace std;

int		main(void)
{
	int			n;
	long long	ret;
	long long	price;
	int			index;
	cin >> n;
	vector<long long> distance(n - 1);
	vector<long long> oil_price(n);

	for (index = 0; index < n - 1; index++)
		cin >> distance[index];
	for (index = 0; index < n; index++)
		cin >> oil_price[index];
	
	ret = distance[0] * oil_price[0];
	price = oil_price[0];
	for (index = 1; index < n - 1; index++)
	{
		if (price > oil_price[index])
			price = oil_price[index];
		ret = distance[index] * price + ret;
	}
	cout << ret;
	return (0);
}
		 



