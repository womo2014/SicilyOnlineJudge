#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int num);

int main()
{
	int n;
	cin >> n;
	
	int cnt = 0;
	if ( n > 1 )
		cnt++;
	for (int i = 3;i <= n; i += 2 )
	{
		int number = pow(2, i) - 1;
		if ( isPrime(number) )
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
int isPrime(int num)
{
	int ret = 1;
	if ( num == 1 )
		ret = 0;
	else for (int j = 2; j <= sqrt(num); j++ )
		if ( num % j == 0 )
		{
			ret = 0;
			break;
		}
	return ret;
}
