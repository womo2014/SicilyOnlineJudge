#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string page[21];
int main()
{
	while ( 1)
	{
		int cnt = 0;
		while ( cin >> page[cnt] ) 
		{
			if ( page[cnt][0] == '0' ) break;
			cnt++;
		}
		if ( cnt == 0 ) break;
		int first = 1;
		string a,b;
		a = b = page[0];
		for ( int i = 1; i <= cnt; i++ )
		{
			if ( page[i].size()-b.size() <= 1 )
			{
				string t;
				t = "0"+b;
				
				t[t.size()-1]++;
				for ( int j = t.size()-1; j >= 0; j-- )
				{
					if ( t[j] <= '9' )break;
					else {
						t[j-1]++;
						t[j] = '0' ;
					}
				}
				if ( t[0] == '0' )
				{
					if ( t.substr(1) == page[i] )
					{
						b = page[i]; continue;
					}
				}
				else if ( t == page[i] )
				{
					b = page[i];continue;
				}
			}
			if ( first )first = 0;
			else printf(",");
			if ( a == b ) cout << a;
			else cout << a << '-' << b;
			a = b = page[i];
		}
		printf("\n");
		
		
	}
	
	
	return 0;
}
