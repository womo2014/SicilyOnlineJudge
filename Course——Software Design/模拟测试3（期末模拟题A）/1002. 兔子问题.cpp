#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a[100];
int dp( int n )
{
	if ( n <= 2 ) return 0;
	if ( a[n] != -1 ) return a[n];
	{
		int &sum = a[n];
		n -= 2;
		sum = 0;
		for ( int i = 0; i < n; i++ )
		{   
			sum += 2 + dp(n-i);
		}
		return sum;
	}
}

int main()
{
	int n;
	memset(a,-1,sizeof(a));
	while ( cin >> n && n != -1)
	{
		cout << dp(n)+2 << endl;
	}

	return 0;
}