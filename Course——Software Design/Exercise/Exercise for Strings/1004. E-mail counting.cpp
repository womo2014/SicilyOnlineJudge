//1004. E-mail counting
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	while ( cin >> n && n )
	{
		string a[n];
		int i;
		int cnt = 0;
		for ( i = 0; i < n; i++ )
		{
			cin >> a[i];
			int j;
			int ret = 0;
			for ( j = 0; a[i][j] != '@' && j < a[i].size(); j++ )
			{
				if ( a[i][j] >= '0' && a[i][j] <= '9' ||
					 a[i][j] >= 'A' && a[i][j] <= 'Z' ||
					 a[i][j] >= 'a' && a[i][j] <= 'z' );
				else {
					ret = 1;
					break;
				}
			}
			if ( j == 0 || j == a[i].size() - 1 || ret )
			{
				continue;
			}
			int cnt1 = 0;
			if ( a[i][j+1] == '.' )
				continue;
			for ( j++; j < a[i].size(); j++ )
			{
				if ( a[i][j] >= '0' && a[i][j] <= '9' ||
					 a[i][j] >= 'A' && a[i][j] <= 'Z' ||
					 a[i][j] >= 'a' && a[i][j] <= 'z' );
				else if ( j < a[i].size() - 1 && a[i][j] == '.' && a[i][j+1] != '.' )
				{
					cnt1++;
				}
				else {
					ret = 1;
					break;
				}
			}
			if ( ret )
			{
				continue;
			}
			else if ( cnt1 > 0 )
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	} 
	return 0;
}
