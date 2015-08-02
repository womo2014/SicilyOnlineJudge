#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while ( n-- )
	{
		string a, b, c;
		cin >> a >> b >> c;
		if ( a.size() > b.size() ) a.swap(b);
		if ( a.size() > c.size() ) a.swap(c);
		if ( b.size() > c.size() ) b.swap(c);
		cout << a << b << c << endl;
	}
	
	return 0;
}
