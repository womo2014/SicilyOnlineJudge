#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	while ( cin >> a && a[0] != '#' )
	{
		int A = a.size();
		if ( A == 4 )
		{
			cout << 90 << endl;
		}
		else if ( A == 5 )
		{
			cout << 0 << endl;
		}
		else
		{
			int degree;
			if ( a[A-4] == 'w')
			{
				degree = 90;
				A -= 4;
			}
			else 
			{
				degree = 0;
				A -= 5;
			}
			int x = 1;
			int b;
			int c;
			for (b = A; b - 4 >= 0; b = b - c )
			{			
				if ( a[b-4] == 'w' )
				{
					c = 4;
					degree = degree*2 + 90;
				}
				else 
				{
					c = 5;
					degree = degree*2 - 90;
				}
				x *= 2;	
			}
			while ( degree % 2 == 0 )
			{
				degree /= 2;
				x /= 2;
			}
			if ( x == 1 )
			{
				cout << degree << endl;
			}
			else
				cout << degree << '/' << x << endl;
		}
	}
	return 0;
}
