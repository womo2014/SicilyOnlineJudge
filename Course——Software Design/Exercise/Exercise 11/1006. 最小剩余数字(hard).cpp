#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

char num[100000+5];

int main()
{

	int n, k;
	while ( scanf("%d %d %s",&n, &k, num) != EOF )
	{
		string a = num;
		int p = 0;
		while ( k != 0 )
		{
			if ( p+k == n)
			{
				a.erase(p);
				k = 0;
			}
			else {	
				char min = a[p];
				int min_i = p;
				for ( int i = p; i <= p+k; i++)
				{
					if ( min > a[i])
					{
						min = a[i];
						min_i = i;
					}
				}
				a.erase(p,min_i-p);
				k -= min_i-p;
				n -= min_i-p;
				p++;
			}
		}
		cout << a << '\n';
	}
	
	
	return 0;
}
