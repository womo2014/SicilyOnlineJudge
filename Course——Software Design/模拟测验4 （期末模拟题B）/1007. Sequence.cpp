#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
int a, b;
int d[10001];
int f( int n )
{
	if ( d[n] != -1 )return d[n];
	else {
		d[n-1] = f(n-1);
		d[n-2] = f(n-2);
		return d[n] = (a*d[n-2]+b*d[n-1])%10;
	}
}
int main()
{
	int n;
	while ( scanf("%d %d %d", &a, &b, &n) && a )
	{
		memset(d,-1,sizeof(d));
		d[1] = d[2] = 1;
		printf("%d\n", f(n) );
	}
	return 0;
}




