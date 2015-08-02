#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a;
	char b[80][2];
	while ( cin >> a && a != "*" )
	{
		int len = a.size();
		int flag1, flag2, flag3;
		flag1 = flag2 = flag3 = 0;
		for ( int i = 1; i < len-1; i++ )
		{
			int cnt = 0;
			for ( int j = 0; j+i < len; j++ )
			{
				for ( int k = 0; k < cnt; k++ )
				{
					if ( b[k][0] == a[j] && b[k][1] == a[j+i] )
					{
						flag3 = 1;
						break;
					}
				}
				if ( flag3 )
				{
					flag2 = 1;
					break;
				}
				else {
					b[cnt][0] = a[j];
					b[cnt][1] = a[j+i];
					cnt++;
				}
			}
			if ( flag2 )
			{
				flag1 = 1;
				break;
			}
		}
		if ( flag1 ) cout << a << " is NOT surprising." << endl;
		else cout << a << " is surprising." << endl;
	}
	return 0;
}