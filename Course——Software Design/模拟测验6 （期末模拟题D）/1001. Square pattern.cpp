#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for ( int i = 0; i <= n/2; i++ )
	{
		int j;
		for ( j = 0; j < i; j++ )
			cout << "-";
		for (; j < n-i; j++ )
			cout << "+";
		for (; j < n; j++ )
			cout << "-";
		cout << endl;
	}
	for ( int i = n/2-1; i >=0; i-- )
	{
		int j;
		for ( j = 0; j < i; j++ )
			cout << "-";
		for (; j < n-i; j++ )
			cout << "+";
		for (; j < n; j++ )
			cout << "-";
		cout << endl;
	}
	return 0;
}

