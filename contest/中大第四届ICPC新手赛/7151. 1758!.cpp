#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n, m, k, x, y, pv;
	string name, step;
	
	while ( cin >> n >> m >> k && n )
	{
		while ( k-- )
		{
			cin >> name >> x >> y >> pv >> step;
			int flag = 1;
			for ( int i = 0; i < step.size(); i++ )
			{
				if ( step[i] == 'N' )
				{
					if( y == m-1 )
					{
						if ( pv < 0 )
						{
							cout << name << " is out of square!\n";
							flag = 0;
							break;
						}
						else if ( pv == 0 );
						else y = 0;
					}
					else y++;
				} 
				else if ( step[i] == 'S' )
				{
					if( y == 0 )
					{
						if ( pv < 0 )
						{
							cout << name << " is out of square!\n";
							flag  = 0;
							break;
						}
						else if ( pv == 0 );
						else y = m-1;
					}
					else y--;
				}
				else if ( step[i] == 'E' )
				{
					if( x == n-1 )
					{
						if ( pv < 0 )
						{
							cout << name << " is out of square!\n";
							flag = 0;
							break;
						}
						else if ( pv == 0 );
						else x = 0;
					}
					else x++;
				}
				else if ( step[i] == 'W' )
				{
					if( x == 0 )
					{
						if ( pv < 0 )
						{
							cout << name << " is out of square!\n";
							flag = 0;
							break;
						}
						else if ( pv == 0 );
						else x = n-1;
					}
					else x--;
				}
			}
			if ( flag )
				cout << x << ' ' << y << "\n";
		}
		cout << "\n";
	}
	
	
	return 0;
}
