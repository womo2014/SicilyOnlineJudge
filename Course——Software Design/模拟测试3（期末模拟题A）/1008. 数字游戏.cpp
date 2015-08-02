#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool check(int num, int a[3] )
{
	int p[4] = {0}, q[4] = {0}, x[10] = {0}, cnt = 0;
	while ( num )
	{
		p[cnt++] = num % 10;
		x[num%10]++;
		num /= 10;
	}
	int t = a[0];
	cnt = 0;
	while ( t )
	{
		q[cnt++] = t % 10;
		x[t%10]--;
		t /= 10;
	}
	cnt = 0;
	for ( int i = 0; i < 4; i++ )
		if ( p[i] == q[i] )cnt++;
	
	int temp = 0;
	for ( int i = 0; i < 10; i++ )
		if ( x[i] > 0 )temp += x[i];
	if ( 4-temp == a[1] &&  cnt == a[2] )return true;
	else return false;

}

int main()
{
	int n;
	int re[100][3];
	while ( cin >> n && n )
	{
		int ret = 0, cnt = 0;
		for ( int i = 0; i < n; i++ )
			cin >> re[i][0] >> re[i][1] >> re[i][2];
		for ( int i = 1000; i <= 9999; i++ )
		{
			int cnt1 = 0;
			for ( int j = 0; j < n ; j++ )
			{
				if ( check(i,re[j]) ) cnt1++;
				else break;
			}
			if ( cnt1 == n )
			{
				ret = i;
				cnt++;
			}
		}
		if ( cnt == 1 ) cout << ret << endl;
		else cout << "Not sure" << endl;
	}

	return 0;
}

int gcd(int a, int b)
{
	return a%b?gcd(b,a%b):b;
}