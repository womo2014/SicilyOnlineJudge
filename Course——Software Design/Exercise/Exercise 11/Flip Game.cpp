#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a[5][5];
int temp[5][5];
int min_step = 17;
bool b[5][5];
bool c[5][5];

bool ok()
{
	for ( int i = 0; i < 4; i++ )
		for ( int j = 0; j < 4; j++ )
			if ( a[0][0] != a[i][j] )return false;
	return true;
}

void choose( int i, int j) 
{
	a[i][j] *= -1;
	if ( j+1 < 4 )a[i][j+1] *= -1;
	if ( i+1 < 4 )a[i+1][j] *= -1;
	if ( j-1 >= 0 )a[i][j-1] *= -1;
	if ( i-1 >= 0 )a[i-1][j] *= -1; 
}

void dfs(int cur, int x, int y)
{
	if ( cur < min_step )
	{
		if ( ok() ) min_step = cur;
		else
		for( int i = 0; i < 4; i++ )
			for ( int j = 0; j < 4; j++ )
			if ( i > x || (i == x && j > y ) )
			{
				choose(i,j);
				dfs(cur+1, i, j);
				choose(i,j);
			}			
	}	
}

int main()
{
	string str;
	for ( int i = 0; i < 4; i++ )
	{
		cin >> str;
		for ( int j = 0; j < 4; j++ )
		{
			if (str[j] == 'b' ){
				a[i][j] = 1;
			}
			else {
				a[i][j] = -1;
			}
		}	
	}
	dfs(0, -1, -1);
	if ( min_step == 17 ) cout << "Impossible" << endl;
	else cout << min_step << endl; 
	
	return 0;
}
