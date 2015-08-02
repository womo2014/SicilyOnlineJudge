#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

char room[50][50];
int cnt;
int a, b;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
void dfs( int x, int y )
{
	for ( int i = 0; i < 4; i++ )
	{
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];
		if ( x1 >= 0 && y1 >= 0 && x1 < b && y1 < a 
			&& room[x1][y1] == '.' )
		{
			cnt++;
			room[x1][y1] = '#';
			dfs(x1,y1);
		}
	}
}
int main()
{
	while ( scanf("%d %d",&a, &b) && a )
	{
		int x = -1,y = -1;
		cnt = 1;
		for ( int i = 0; i < b; i++ )
			for ( int j = 0; j < a; j++ )
			{	
				cin >> room[i][j];
				if ( room[i][j] == '@' )
				{
					x = i;
					y = j;
				}
			}
		if ( x == -1 )cnt = 0;
		else dfs(x,y);
		printf("%d\n", cnt);
	}
	return 0;
}