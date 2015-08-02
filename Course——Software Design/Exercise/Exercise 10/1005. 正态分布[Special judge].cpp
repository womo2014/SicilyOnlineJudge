#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double a, b, n;
	
	while ( scanf("%lf %lf %lf", &a, &b, &n) != EOF)
	{
		double x = (b-a)/(3*n*sqrt(2*acos(-1)) );
		double sum = exp(-a*a/4)+exp(-b*b/4);
		for ( int i = 1; i <= n-1; i += 2 )
		{
			sum += 4*exp(-pow( (a+i*(b-a)/n)/2 ,2));
		}
		for ( int i = 2; i <= n-2; i += 2 )
		{
			sum += 2*exp(-pow( (a+i*(b-a)/n)/2 ,2));
		}
		printf("%.2lf\n",sum*x);
	}
	
	return 0;
}
