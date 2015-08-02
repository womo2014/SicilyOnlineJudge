#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s1,s2;
	int a[255];
	int b[255];
	int c[255];
	while ( n-- )
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin >> s1 >> s2;
		for ( int i = 0; i < s1.size(); i++ )
		{
			a[s1[i]]++;
		}
		for ( int i = 0; i < s2.size(); i++ )
		{
			b[s2[i]]++;
		}
		int flag = 0;
		for ( int i = 'a'; i <= 'z'; i++ )
		{
			for ( int j = 0; j < min(a[i],b[i]); j++ )
			{	
				printf("%c",i);
				flag = 1;
			}
		}
		if ( flag ) printf("\n");
	}
	return 0;
}




