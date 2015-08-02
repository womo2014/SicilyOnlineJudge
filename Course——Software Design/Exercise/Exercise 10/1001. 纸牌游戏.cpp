#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int num[50];

void process(int n)
{
	printf("%d ",num[1] );
	if ( n == 1 );
	else {
		int t = num[2];
		for ( int i = 1; i <= n-2; i++ )
			num[i] = num[i+2];
		num[n-1] = t;
		process(n-1);
	}
}

int main()
{
	int t, n;
	cin >> t;
	while ( t-- )
	{
		scanf("%d",&n);
		for ( int i = 1; i <= n; i++ )
			num[i] = i;
		process(n);
		printf("\n");
	}
	
	return 0;
}
