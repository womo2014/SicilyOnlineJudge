//1004. T-primes
#include <iostream>
#include <cmath>

using namespace std;
long long my_sqrt( long long n );

int main()
{
	int n;
	cin >> n;
	long long x;
	int t_cnt = 0;
	while ( n-- )
	{
		cin >> x;
		int copy = my_sqrt(x);
		if ( copy != -1 )
		{
			int judge = 1;
			for ( int i = 2; i*i <= copy; i++ )
			{
				if ( copy % i == 0 )
				{
					judge = 0;
					break;
				}
			}
			if ( judge )
				t_cnt++;
		}
	}
	cout << t_cnt << endl;
	return 0;
}
long long my_sqrt( long long n )
{
	int ret = -1;
	long long a = 0, b = n;
	long long s = (a+b)/2;
	while ( a != b-1 )
	{
		if ( s*s == n )
		{
			ret = s;
			a = b-1;
		}
		else
		{
			if ( s*s > n || s*s <= 0 )
				b = s;
			else 
				a = s;
			s = (a+b)/2;
		}
	}
	return ret;
}
