#include <iostream>

using namespace std;

int main()
{
	long long  n, m;

	while ( cin >> n >> m )
	{
		if ( n == -1 && m == -1 ) break;
		long long  x0 = 0, x1 = 1;
		long long x;
		if ( n >= 10000)
		{
			int t_x0 = x0;
			int t_x1 = x1;
			int a, b, c;
			for ( int i = 2; i <= 10000; i++ )
			{
				a = t_x0;
				x = ( t_x0 + t_x1 )%m;
				t_x0 = t_x1;
				t_x1 = x;
			}
			b = t_x0;
			c = x; 
			while ( n >= 10000)
			{
				int tt_x0 = ( (x0*a)%m + (x1*b)%m )%m;
				x1 = ( (x0*b)%m + (x1*c)%m )%m;
				x =(tt_x0 + x1) % m;
				x0 = x1;
				x1 = x;
				n -= 10000;
			}
		}
		
		if ( n == 0 )
			cout << x0 << endl;
		else if ( n == 1 )
			cout << x1 << endl;
		else {
			for ( int i = 0; i <= n-2; i++ )
			{
				x = ( x0 + x1 )%m;
				x0 = x1;
				x1 = x;
			}		
			cout << x << endl;
		}
	}
	return 0;
}
