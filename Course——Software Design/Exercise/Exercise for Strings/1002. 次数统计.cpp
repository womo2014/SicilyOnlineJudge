//1002. 次数统计
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	while ( cin >> a )
	{
		cin >> b;
		int cnt = 0;
		int i, j;
		for ( i = 0; i <= a.size() - b.size(); i++ )
		{
			int ret = 1;
			for ( j = 0; j < b.size(); j++ )
			{
				if ( b[j] != a[i+j] )
				{
					ret = 0;
					break;
				}
			}
			if ( ret )
			{
				cnt++;
				i += b.size() - 1;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;	
}
