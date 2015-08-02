#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int n;
		cin >> n;
		if ( n % 6 == 0 ) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}

