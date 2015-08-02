#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n, m, p;
	long long a[50][50],b[50][50];
	long long c[50][50] = {0,};
	while ( scanf("%d %d %d", &n, &m, &p) != EOF)
	{
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < m; j++ )
				scanf("%lld",&a[i][j]);
		
		for ( int i = 0; i < m; i++ )
			for ( int j = 0; j < p; j++ )
				scanf("%lld",&b[i][j]);		
		
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < p; j++ )
				for ( int k = 0; k < m; k++ )
					c[i][j] += a[i][k]*b[k][j];
		
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < p-1; j++ )
				printf("%lld ",c[i][j]);
			printf("%lld\n",c[i][p-1]);
		}
	}
	return 0;
}
