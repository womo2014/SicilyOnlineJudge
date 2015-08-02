#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
int num[1000001];
int stack[1000001];
int main()
{
	int t;
	scanf("%d",&t);
	int n;

	while ( t-- )
	{
		int cnt = 0;
		num[1][1] = 0;
		scanf("%d",&n);
		long long count = 0;
		for ( int i = 1; i <= n; i++ )
		{
			scanf("%d",&num[i][0]);
			for ( int j = cnt-1; j >= 1; j-- )
			{	
				if ( num[j][0] > num[i][0] )
				{ 	
					cnt += j; stack[cnt++] = j; break;
				}
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}