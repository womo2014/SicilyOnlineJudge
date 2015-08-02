#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, n, size;
int ok;
int sequen[1001];
bool c[1001];


bool prime(int num)
{
	if ( num == 1 ) return false;
	for ( int i = 2; i <= sqrt(num); i++ )
		if ( num % i == 0 )return false;
	return true;
}
void dfs( int cur )
{
	if ( ok )return;
	if ( cur > size )
	{
		for ( int i = 1; i <= size; i++ )
		{
			if ( i != 1 ) printf(",");
			printf("%d", sequen[i]);
		}
		printf("\n");
		ok = 1;
	}
	for ( int i = a; i <= b; i++ )
	{
		if ( ok )break;
		if ( !c[i] )
		{
			sequen[cur] = i;
			int flag = 1;
			int sum = i;
			for ( int j = 2; j <= n && j <= cur; j++)
				if ( prime((sum += sequen[cur-j+1])) )
				{
					flag = 0;
					break;
				}
			if ( flag )	
			{
				c[i] = true;
				dfs(cur+1);
				c[i] = false;
			}
		}
	}
}

int main()
{
	while ( scanf("%d %d %d",&a, &b, &n) != EOF && a )
	{
		memset(c,0,sizeof(c));
		ok = 0;
		size = b-a+1;
		dfs(1);
		if ( !ok )printf("No anti-prime sequence exists.\n");
	}
	return 0;
}