#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(char a, char b )
{
	return a > b;
}
int main()
{
	char num[101];
	int n;
	cin >> n;
	while ( n-- )
	{
		cin >> num;
		int l = 0;
		int len = strlen(num);
		for ( int i = 0; i < len; i++ )
		{
			if ( num[i] == '0' )
			{
				if ( i >= l)
					sort(num+l,num+i,cmp);
				l = i+1;
			}
		}
		sort(num+l,num+len,cmp);
		cout << num << endl;
	}
	return 0;
}