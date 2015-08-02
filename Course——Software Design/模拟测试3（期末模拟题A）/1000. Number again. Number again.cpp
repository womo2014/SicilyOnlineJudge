#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool check(int num)
{
	int digit[10], cnt = 0;
	while ( num )
	{
		digit[cnt++] = num%10;
		num /= 10;
	}
	for ( int i = 1; i < cnt-1; i++ )
	{
		if ( digit[i] == fabs(digit[i+1]-digit[i-1]) 
			||  digit[i] == digit[i+1]+digit[i-1] );
		else return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for ( int i = 1; i <= n; i++ )
		if ( check(i) )cnt++;
	cout << cnt << endl;

	return 0;
}