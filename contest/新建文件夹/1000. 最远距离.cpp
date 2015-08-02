#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int x[101],y[101];
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	
	int a = 1, b = 2;
	
	double max_d = sqrt( (x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]) );
	
	for ( int i = 1; i < n; i++ )
		for ( int j = i+1; j <= n; j++ )
		{
			double d = sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );
			if ( (float)max_d < (float)d )
			{
				max_d = d;
				a = i;
				b = j;
			}
		}
	printf("%.4f %d %d\n",max_d, a, b);
	
	
	return 0;
}
