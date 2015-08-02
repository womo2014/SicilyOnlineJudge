#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int p[100000];

int main()
{
	int n;
	scanf("%d", &n);
	bool buy = false;
	int a, b;
	int sum = 0;
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d", &p[i]);
		if ( i != 0 )
		{
			if ( !buy )
			{
				if ( p[i-1] < p[i] )
				{
					buy = true;
					a = p[i-1];
				}
			}
			else {
				if ( p[i-1] > p[i] )
				{
					buy = false;
					sum += p[i-1]-a;
				}
			}
		}

	}
	if ( buy ) sum += p[n-1]-a;

	cout << sum << endl;
	return 0;
}

