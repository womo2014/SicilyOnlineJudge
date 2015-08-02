#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	while ( scanf("%d",&n) && n)
	{
		int cnt = 0;
		for ( int i = 2; i <= n; i++ )
		{
			if ( n % i == 0 )
			{
				cnt++;
				while ( n % i == 0 )
				{
					n /= i;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}




