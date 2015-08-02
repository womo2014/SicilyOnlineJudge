//1003. Mirror, Mirror on the Wall
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	while ( cin >> a && a[0] != '#' )
	{
		int i;
		int ret = 1;
		string b;
		for ( i = a.size() - 1; i >= 0; i-- )
		{
			if ( a[i] == 'b' )
				b += 'd';
			else if ( a[i] == 'd' )
				b += 'b';
			else if ( a[i] == 'p' )
				b += 'q';
			else if ( a[i] == 'q' )
				b += 'p';
			else if ( a[i] == 'i' ||
					  a[i] == 'o' ||
					  a[i] == 'v' ||
					  a[i] == 'w' ||
					  a[i] == 'x' ) 
			{
				b += a[i];
			}
			else {
				cout << "INVALID" << endl;
				ret = 0;
				break;
			}
		}
		if ( ret )
		{
			cout << b << endl;
		}
	}
	return 0;
}
