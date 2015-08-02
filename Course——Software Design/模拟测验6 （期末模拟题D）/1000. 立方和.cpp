#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int n;
		cin >> n;
		int sum = 0;
		for ( int i = 1; i <= n; i++ )
		{
			sum += i*i*i;
		}
		cout << sum << endl;
	}
	return 0;
}

