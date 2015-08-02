#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int reverse( int n )
{
	int ret = 0;
	while ( n )
	{
		ret = ret*10 + n%10;
		n /= 10;
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
		while ( n != reverse(n) )
		{
			n += reverse(n);
		}
		cout << n << endl;; 
	}	
	return 0;
}

