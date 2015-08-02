#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

int x[10000];
int y[10000];

using namespace std;

int main()
{
	int t, n;
	scanf("%d",&t);
	while ( t-- )
	{
		cin >> n;
		int max_x,max_y,min_x,min_y;
		max_x = max_y = -10001;
		min_x = min_y = 10001;
		for ( int i = 0; i < n; i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			if ( min_x > x[i] ) min_x  = x[i];
			else if ( max_x < x[i] ) max_x = x[i];
			if ( min_y > y[i] ) min_y = y[i];
			else if ( max_y < y[i] ) max_y = y[i];
		}
		int  flag = 1;
		for ( int i = 0; i < n; i++ )
		{
			if (!( x[i] == min_x || x[i] == max_x || y[i] == max_y || y[i] == min_y ))
			{
				flag = 0;
				break;
			}
		}
		if ( flag ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
