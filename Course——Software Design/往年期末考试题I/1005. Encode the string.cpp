#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string a;
	char now_c;
	int cnt;
	while ( cin >> a )
	{
		int len = a.size();
		now_c = a[0];
		cnt = 1;
		for ( int i = 1; i < len; i++ )
		{
			if ( now_c == a[i] ) cnt++;
			else {
				cout << now_c;
				if ( cnt > 1 )cout << cnt;
				cnt = 1;
				now_c = a[i];
			}
		}
		cout << now_c;
		if ( cnt > 1) cout << cnt;
		cout << endl;
	}
	return 0;
}