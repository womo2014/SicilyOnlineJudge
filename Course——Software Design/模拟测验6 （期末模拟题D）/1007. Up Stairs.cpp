#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int dp( int n )
{
	if ( n == 0 ) return 1;
	int ret = 0;
	for ( int i = 1; i <= 3 && i <= n; i++ )
	{
		ret += dp(n-i);
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	
	while ( t-- )
	{
		int n;
		cin >> n;
		cout << dp(n) << endl;
	}
	return 0;
}

