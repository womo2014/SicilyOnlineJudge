#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t); 
	int s[107];
	while ( t-- )
	{
		int n;
		scanf("%d",&n);
		for ( int i = 0; i < n; i++)
			scanf("%d",&s[i]);
		int cnt = 0;
		for ( int i = 0;i < n-2; i++ )
			for ( int j = i+1; j < n-1; j++ )
				for ( int k = j+1; k < n; k++)
					if ( s[i]+s[j] > s[k] && s[i] + s[k] > s[j] && s[j] + s[k] > s[i])
						cnt++;
		printf("%d\n",cnt);
	}
	
	return 0;
} 

