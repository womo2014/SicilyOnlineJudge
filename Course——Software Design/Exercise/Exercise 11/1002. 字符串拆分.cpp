#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	while  ( cin >> a )
	{
		string b, c;
		for ( int i = 0; i < a.size(); ++i )
		{
			if ( i & 1)
				c += a[i];
			else 
				b += a[i];
		}
		cout << b << ',' << c << endl;		
	}


	return 0;
}
