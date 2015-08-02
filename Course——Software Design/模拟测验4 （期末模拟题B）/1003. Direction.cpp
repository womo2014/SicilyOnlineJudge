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
	string a;
	while ( n-- )
	{
		int ret = 0;
		cin >> a;
		for ( int i = 0; i < a.size(); i++ )
		{
			if ( a[i] == 'L' )ret += 3;
			else ret++;
		}
		if ( ret % 4 == 0 ) cout << "N" << endl;
		else if ( ret % 4 == 1 ) cout << "E" << endl;
		else if ( ret % 4 == 2 )cout << "S" << endl;
		else cout << "W" << endl;
	}
	return 0;
}




