#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int a[2][2];
	int n;
	cin >> n;
	while ( n-- )
	{
		cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
		if ( a[0][0] == a[1][1] ) cout << "Yes" << endl;
		else cout << "No" <<endl;
	}
	return 0;
}