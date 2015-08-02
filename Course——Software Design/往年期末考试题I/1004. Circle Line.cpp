#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n，a, b;
	cin >> n;
	int d[101];
	for ( int i = 1; i <= n; i++ )
		cin >> d[i];
	cin >> a >> b;
	int i = a;
	int cnt1 = 0, cnt2 = 0;
	while( i != b )
	{
		cnt1 += d[i++];
		if ( i > n) i = 1;
	}
	i = a;
	while ( i != b )
	{
		if ( i == 1 ) cnt2 += d[(i = n)];
		else cnt2 += d[--i];
	}
	cout << (cnt1<cnt2?cnt1:cnt2) << endl;
	return 0;
}