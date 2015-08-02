#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	string a;
	while ( cin >> n >> m )
	{
		for ( int i = 0; i < n; i++ )
		{
			cin >> a;
			for ( int j = m-1; j >= 0; j-- )
			{
				if ( a[j] == 'b') cout << 'd';
				else cout << a[j];
			}
			cout << endl;
		}
		cout << endl;
	
	}

	return 0;
}
