#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int a[30001] = {0,0};
	for ( int i = 2; i <= 3000; i++ )
	{
		int &sum = a[i] = 1;
		for ( int j = 1; j < i; j++ )
		{
			if ( i % j == 0 )
			{
				sum += j;
			}
		}
	}
	for ( int i = 1; i <= 3000; i++ )
	{
		for ( int j = i+1; j <= 3000; j++ )
			if ( a[i] == j && a[j] == i ) cout << i << ' ' << j << endl;
	}

	return 0;
}