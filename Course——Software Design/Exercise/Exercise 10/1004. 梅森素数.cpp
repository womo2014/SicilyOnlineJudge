#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int is_prime( int n)
{
	if ( n == 1 ) return 0;
	else for ( int i = 2; i <= sqrt(n)+0.5; i++ )
	{
		if ( n % i  == 0 )return 0;
	}
	return 1;
}

int main()
{
	int p;
	while ( scanf("%d",&p) != EOF)
	{
		if ( is_prime(p) && is_prime(pow(2,p)-1) ) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
