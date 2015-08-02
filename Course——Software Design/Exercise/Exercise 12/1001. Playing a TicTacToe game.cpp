#include <iostream>

using namespace std;

char grid[4][4];

void ini()
{
	for ( int i = 0; i <= 3; i++ )
		for ( int j = 0; j <= 3; j++ )
			grid[i][j] = '\0';
}
char check()
{
	
	for ( int i = 1; i <= 3; i++ )
	{
		for ( int j = 1; j <= 2; j++ )
		{
			if (grid[i][j+1] == '\0' || grid[i][j] != grid[i][j+1] )break;
			else if ( j == 2 )return grid[i][j];
		}
	}
	for ( int i = 1; i <= 3; i++ )
	{
		for ( int j = 1; j <= 2; j++ )
		{
			if (grid[j+1][i] == '\0' || grid[j][i] != grid[j+1][i] )break;
			else if ( j == 2 )return grid[j][i];
		}
	}
	for ( int i = 1; i <= 2; i++ )
	{
			if (grid[i+1][i+1] == '\0' || grid[i][i] != grid[i+1][i+1] )break;
			else if ( i == 2 )return grid[i][i];
	}
	for ( int i = 1; i <= 2; i++ )
	{
			if (grid[i+1][3-i] == '\0' || grid[i][4-i] != grid[i+1][3-i] )break;
			else if ( i == 2 )return grid[i][4-i];
	}
	return '\0';
}

int main()
{
	int x, y;
	string a;	
	int t;
	cin >> t;
	for ( int k = 1; k <= t; k++ )
	{
		cout << "test case " << k << ":\n";
		ini();
		int n;
		cin >> n;
		for ( int i = 1; i <= n; i++ )
		{
			cin >> x >> y >> a;
			grid[x][y] = a[0];
			char temp = check();

			if ( temp == '\0' )
			{
				if ( i == 9 ) cout << "draw" << endl;
				else cout << "unfished" << endl;
			
			} 
			else if ( temp == 'X')cout << "player1 won" << endl;
			else cout << "player2 won" << endl;
		}
		
	}
	
	return 0;
}
