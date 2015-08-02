#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[1000];
bool check(int n )
{
	for ( int i = 1; i < n; i++ )
		if ( num[i] != num[0] )return true;
	return false;
}

int main()
{
	int n;
	while ( scanf("%d",&n) && n )
	{	
		for ( int i = 0; i < n; i++ )
			scanf("%d",&num[i]);
		int cnt = 0;
		do{
			cnt++;
			int t = num[0];
			for ( int i = 0; i < n-1; i++ )
			{
				num[i] = num[i]/2 + num[i+1]/2;
				if ( num[i] & 1 )++num[i];
			}
			num[n-1] = num[n-1]/2+t/2;
			if ( num[n-1] & 1 )++num[n-1]; 
		}while ( check(n) );
		cout << cnt << ' ' << num[0] << endl;
	}
	return 0;
}