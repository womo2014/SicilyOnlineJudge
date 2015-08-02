//1198. Substring
//最小字典序组合strA < strB 的条件是 strA + strB < strB + strA!!! 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	while ( T-- )
	{
		int n; 
		cin >> n;
		string a[8];
		int i;
		for ( i = 0; i < n; i++ )
		{
			cin >> a[i];
		}
		for ( i = 1; i < n; i++ )
		{
			if ( a[i] + a[i-1] < a[i-1] + a[i] )
			{
				int j = i-1;
				string b = a[i];
				a[i] = a[i-1];
				while ( j >= 0 && b + a[j] < a[j] + b )
				{
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = b;
			}
		}
		for ( i = 0; i < n; i++ )
		{
			cout << a[i];
		}
		cout << endl;
	}
	
	return 0;
}
