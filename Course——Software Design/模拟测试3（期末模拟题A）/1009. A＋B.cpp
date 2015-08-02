#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	while ( cin >> a >> b )
	{
		int num1 = 0, num2 = 0;
		for ( int i = 0; i < a.size(); i++ )
			if ( a[i] != ',' && a[i] != '-' ) num1 = num1*10 + a[i]-'0'; 
		if ( a[0] == '-' ) num1 *= -1;
		
		for ( int i = 0; i < b.size(); i++ )
			if ( b[i] != ',' && b[i] != '-' ) num2 = num2*10 + b[i]-'0'; 
		if ( b[0] == '-' ) num2 *= -1;
		
		cout << num1+num2 << endl;
	}
	return 0;
}