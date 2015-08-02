#include <iostream>

using namespace std;

int main()
{
	long long  n, m;
	
	while ( cin >> n >> m )
	{
		if ( n == -1 && m == -1 ) break;
		unsigned long long  x0 = 0, x1 = 1;
		unsigned long long x;
		if ( n == 0 )
			cout << x0 << endl;
		else if ( n == 1 )
			cout << x1 << endl;
		else {
			for ( int i = 0; i <= n-2; i++ )
			{
				x = ( x0 + x1 );
				x0 = x1;
				x1 = x;
				
			}		
			cout << x << endl;
		}
	}
	return 0;
}
