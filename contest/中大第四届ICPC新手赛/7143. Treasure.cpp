#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while ( t-- )
	{
		int n;
		scanf("%d", &n);
		getchar();
		char num[100];
		scanf("%s", num);

		long long x(0), y(0);
		long long len = pow(2, n);
		for (int i = 0; i < n; i++ )
		{
			len /= 2;
			if ( num[i] == '0' );
			else if ( num[i] == '1' )
				y += len;
			else if ( num[i] == '2' )
				x += len;
			else {
				x += len;
				y += len;
			}
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
} 

