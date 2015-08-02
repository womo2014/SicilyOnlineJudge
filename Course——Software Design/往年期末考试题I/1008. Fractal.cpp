#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

char c[1000][1000];

void B(int x, int y, int n)
{
	if ( n == 1 ) c[x][y] = 'X';
	else 
	{
		int t = pow(3,n-2);	
		B(x,y,n-1);
		B(x+t,y+t,n-1);
		B(x+2*t,y,n-1);
		B(x,y+2*t,n-1);
		B(x+2*t,y+2*t,n-1);
	}
}
int main()
{
	memset(c,'.',sizeof(c));
	int n;
	B(1,1,7);
	while ( cin >> n && n != -1 )
	{
		int t = pow(3,n-1);
		for ( int i = 1; i <= t; i++ )
		{
			for ( int j = 1; j <= t; j++ )
				printf("%c", c[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}