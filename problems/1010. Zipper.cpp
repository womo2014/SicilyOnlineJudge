#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int i;
	
	cin >> n;
	
	for ( i = 1; i <= n; i++ )
	{
		string a, b, c;
		cin >> a >> b >> c;
		int ret = 1;
		int cnt1 = 0;
		int cnt2 = 0;
		int j;
		for ( j = 0;j < c.size(); j++ )
		{
			if (a[cnt1] == b[cnt2] && a[cnt1] == c[j])
			{					
				j++;
				for (k = 1; )
				{

					if ( cnt1+k == a.size() )
					{
						if( cnt2+k == a.size() )
						{
							
						}
					}
					if ( a[cnt1+k] == b[cnt2+k] )
					
				}
			}
		}
		if ( cnt1 != a.size() || cnt2 != b.size() )
		{
			ret = 0;
		}
		cout << "Data set " << i << ": ";
		if ( ret ) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}
