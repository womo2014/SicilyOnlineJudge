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
	int a, b;
	while ( cin >> a >> b  && a )
	{
		bool ret = false;
		while ( a*b != 0 )
		{
			ret = !ret;
			if ( a < b ) swap(a, b);
			if ( a % b == 0 ) a = 0;
			else if ( a/b == 1 ) 
				a -= b;
			else break;
		}
		if ( ret ) cout << "Singa wins" << endl;
		else cout << "Suny wins" << endl;
	}

	return 0;
}




