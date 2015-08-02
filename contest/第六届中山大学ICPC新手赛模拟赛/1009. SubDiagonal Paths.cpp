#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
unsigned long long grid[31][31];
int vis[31][31];
unsigned long long dp ( int x , int y) 
{
	if ( y > x || x > n ) return 0;
	if ( vis[x][y] != -1 )return grid[x][y];
	if ( x == n && y == n ) return 1;
	else 
		
		{
			vis[x][y] = 1;
		 return	grid[x][y] = dp(x+1,y)+dp(x,y+1);
		}
}

int main()
{
	while ( cin >> n && n )
	{
		memset(vis,-1,sizeof(int)*31*31);
		memset(grid,0,sizeof(unsigned long long)*31*31);
		n++;
		cout << dp(1,1) << endl;
	}
	return 0;
}
