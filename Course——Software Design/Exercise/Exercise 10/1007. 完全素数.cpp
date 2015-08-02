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
int a[]= {2, 3, 5, 7};
int b[]= {1, 3, 7, 9};
int m;
void check(int num, int p)
{
	if ( p == m ) printf("%d\n",num);
	else {
		for ( int i = 0; i < 4; i++ )
		{
			int t = num*10+b[i];
			if ( is_prime(t)) check(t,p+1);
		}
	}
	
}

int main()
{

	cin >> m;

	int num = 0;
	for ( int i = 0; i < 4; i++ )
	{
		num = num*10+a[i];
		check(num, 1);
		num = 0;
	}
	
	return 0;
}
