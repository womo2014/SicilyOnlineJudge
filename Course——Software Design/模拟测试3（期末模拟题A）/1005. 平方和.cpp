#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int n;
		scanf("%d",&n);
		int d = n*(n+1)*(2*n+1)/6;
		printf("%d\n",d);
	}

	return 0;
}