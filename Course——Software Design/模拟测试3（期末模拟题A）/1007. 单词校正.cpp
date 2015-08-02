#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int posi;
	string str;
	while ( n-- )
	{
		cin >> posi >> str;
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( i+1 != posi )printf("%c",tolower(str[i]));
		}
		cout << endl;

	}

	return 0;
}