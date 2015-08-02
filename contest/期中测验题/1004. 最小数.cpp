#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int num[1000];
	int n;
	scanf("%d", &n);
	
	int  cnt = 0;
	for ( int i = 9; i >=2; i-- )
	{
		while ( n % i == 0 )
		{
			num[++cnt] = i;
			n /= i;
		}
	}
	if ( n > 10 )
		printf("There is no such number.\n");
	else {
		for ( int i = cnt; i > 0; i-- )
			printf("%d", num[i]);
		printf("\n");		
	}
	return 0;
}
