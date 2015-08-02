#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int ret = 0;
	int a(0), b(0);
	char c;
	while (cin >> str)
	{
		a = 0;
		b = 0;
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( str[i] == '+'  || str[i] == '-'|| str[i] == '*'||str[i] == '/')
			{
				c = str[i];
				for ( int j = 0; j < i; j++ )
					a = a*10 + str[j]-'0';
				for ( int j = i+1 ;j < str.size(); j++ )
					b = b*10 + str[j] - '0';
						
				if ( c == '+' )
					cout <<	a+b << endl;
				else if ( c == '-')
					cout << a-b << endl;
				else if ( c == '*' )
					cout << a*b << endl;
				else cout << a/b << endl;
				break;
			}
		}
	}

	return 0;
}
